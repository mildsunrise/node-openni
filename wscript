#!/usr/bin/env python
# encoding: utf-8

def set_options(opt):
    opt.tool_options("compiler_cxx")

def configure(cnf):
    cnf.check_tool("compiler_cxx")
    cnf.check_tool("node_addon")
    cnf.check(features="cxx", lib=["OpenNI"], includes=["/usr/include/ni"], uselib_store="OpenNI")

def build(bld):
    obj = bld.new_task_gen("cxx", "shlib", "node_addon")
    obj.cxxflags = ["-g","-D_FILE_OFFSET_BITS=64","-D_LARGEFILE_SOURCE","-Wall"]
    obj.target = "openni"
    obj.source = ["src/wrapper.cpp","src/wrapperUtils.cpp",
                  "src/Context.cpp",
                  "src/ProductionNode.cpp",
                  "src/Generator.cpp",
                  "src/GestureGenerator.cpp"]
    obj.uselib = ["OpenNI"]
