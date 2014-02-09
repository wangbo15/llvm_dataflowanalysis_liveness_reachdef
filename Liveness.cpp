// 15-745 S13 Assignment 1: FunctionInfo.cpp
// 
// Based on code from Todd C. Mowry
// Modified by Arthur Peters
////////////////////////////////////////////////////////////////////////////////

#include "llvm/Pass.h"
#include "llvm/PassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/raw_ostream.h"


#include "llvm/IR/BasicBlock.h"


#include "llvm/Support/InstIterator.h"

#include "llvm/IR/Constants.h"
#include "llvm/IR/Instructions.h"

#include "llvm/Support/PatternMatch.h"


#include "DataFlow.cpp"


#include <ostream>
#include <fstream>
#include <iostream>

using namespace llvm;

namespace {

	class Liveness : public DataFlow<llvm::Value *>, public FunctionPass {
		public:
			static char ID;
			Liveness() : DataFlow<llvm::Value *>(), FunctionPass(ID) {

			}

			virtual bool runOnFunction(Function &F) {
				std::vector<Value *> domain;
				for (Function::arg_iterator arg = F.arg_begin(); arg != F.arg_end(); ++arg) {
					domain.push_back(arg);
				}
				for (inst_iterator ii = inst_begin(F), ie = inst_end(F); ii != ie; ++ii) {
					if (!ii->getName().empty()) {
						domain.push_back(&*ii);
					}
				}

				//debugging.....
				errs() << "Domain: ";
				for (int i = 0; i < domain.size(); ++i) {
					errs() << domain[i]->getName();
					errs() << ", ";
				}
				errs() << "\n";





			}
			// We don't modify the program, so we preserve all analyses
			virtual void getAnalysisUsage(AnalysisUsage &AU) const {
				AU.setPreservesAll();
			}
	};

	// LLVM uses the address of this static member to identify the pass, so the
	// initialization value is unimportant.
	char Liveness::ID = 0;

	// Register this pass to be used by language front ends.
	// This allows this pass to be called using the command:
	//    clang -c -Xclang -load -Xclang ./FunctionInfo.so loop.c
	static void registerMyPass(const PassManagerBuilder &,
			PassManagerBase &PM) {
		PM.add(new Liveness());
	}
	RegisterStandardPasses
		RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
				registerMyPass);

	// Register the pass name to allow it to be called with opt:
	//    clang -c -emit-llvm loop.c
	//    opt -load ./FunctionInfo.so -function-info loop.bc > /dev/null
	// See http://llvm.org/releases/3.4/docs/WritingAnLLVMPass.html#running-a-pass-with-opt for more info.
	RegisterPass<Liveness> X("my-liveness", "my-liveness");

}