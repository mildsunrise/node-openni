/* ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This file is part of node-openni.
 *
 * node-openni is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * node-openni is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with node-openni.  If not, see <http://www.gnu.org/licenses/>.
 *
 * node-openni is Copyright (C) 2012, Xavier Mendez (jmendeth).
 *
 * ***** END GPL LICENSE BLOCK ***** */

#include "Context.h"

namespace node_xn {

    using namespace v8;
    using namespace node;

    Context Context::Init() {
        XnContext* ptr;
        xnInit(&ptr);
        return Context(ptr);
    }

    void Context::OnConstruct() {
        //FIXME: we should check if ptr == NULL
        xnContextAddRef(this->ptr);
    }

    Context::~Context() {
        xnContextRelease(this->ptr);
    }


    /** WRAPPED METHODS **/

    /* Initializer */
    void Context::INIT(Handle<Object> ctx) {
        HandleScope scope;

        //1. Declare the class prototype
        Local<FunctionTemplate> protoL = FunctionTemplate::New(new_default);
        Persistent<FunctionTemplate> proto = v8::Persistent<FunctionTemplate>::New(protoL);
        proto->InstanceTemplate()->SetInternalFieldCount(1);
        proto->SetClassName(v8::String::NewSymbol("Context"));

        //2. Add accessors

        //3. Bind methods

        //4. Declare static functions' templates
        Local<FunctionTemplate> initSyncL = FunctionTemplate::New(initSync, proto->GetFunction());
        Persistent<FunctionTemplate> initSyncP = Persistent<FunctionTemplate>::New(initSyncL);

        //5. Finally, add the things to the target
        ctx->Set(v8::String::NewSymbol("initSync"), initSyncP->GetFunction());
        ctx->Set(v8::String::NewSymbol("Context"),  proto->GetFunction());
    }

    /* Static factory methods */
    Handle<Value> Context::initSync(const Arguments& args) {
        HandleScope scope;

        Handle<Object> instH = ((Function*)(*args.Data()))->NewInstance();
        (new Context(Init()))->Wrap(instH);

        return instH;
    }

}
