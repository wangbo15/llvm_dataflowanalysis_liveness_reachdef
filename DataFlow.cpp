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

#include "llvm/IR/Constants.h"
#include "llvm/IR/Instructions.h"

#include "llvm/ADT/ValueMap.h"
#include "llvm/ADT/BitVector.h"



#include <ostream>
#include <fstream>
#include <iostream>

using namespace llvm;

namespace {
	template<class T>
	class DataFlow {
		public:
		T a;
		DataFlow() {
		}
		/*
		public:
			ValueMap<BasicBlock*, BitVector*> *in;
			ValueMap<BasicBlock*, BitVector*> *out;
		DataFlow() {
			in = new ValueMap<BasicBlock*, BitVector*>();
			out = new ValueMap<BasicBlock*, BitVector*>();
		}
		*/


		/*
		DataFlow(std::vector<T> domain, bool forward) {

		}
		*/



		virtual 



	};
}
