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

#include "GestureGenerator.h"

namespace node_xn {

    using namespace v8;
    using namespace node;

    void GestureGenerator::Create(const Context& ctx, XnNodeHandle& handle, XnNodeQuery* query) {
        check( xnCreateGestureGenerator(ctx.ptr, &handle, query, NULL) );
    }

    Persistent<FunctionTemplate> INIT_GestureGenerator(Handle<Object> ctx, Persistent<FunctionTemplate> parent) {
        HandleScope scope;

        //1. Declare the class prototype
        Local<FunctionTemplate> protoL = FunctionTemplate::New(new_default);
        Persistent<FunctionTemplate> proto = Persistent<FunctionTemplate>::New(protoL);
        proto->InstanceTemplate()->SetInternalFieldCount(1);
        proto->Inherit(parent);
        proto->SetClassName(v8::String::NewSymbol("GestureGenerator"));

        //2. Add accessors

        //3. Bind methods

        //4. Declare static factory method(s)
        Local<FunctionTemplate> createL = FunctionTemplate::New(GestureGenerator::createGestureGeneratorSync, proto->GetFunction());
        Persistent<FunctionTemplate> create = Persistent<FunctionTemplate>::New(createL);

        //5. Finally, add the things to the target
        ctx->Set(v8::String::NewSymbol("GestureGenerator"), proto->GetFunction());
        ctx->Set(v8::String::NewSymbol("createGestureGeneratorSync"), create->GetFunction());
        return proto;
    }

    Handle<Value> GestureGenerator::createGestureGeneratorSync(const Arguments& args) {
        HandleScope scope;
        try {

            //Check for arguments
            checkArgumentsLen(args, 1);

            //Extract arguments
            Context& ctx = *(Context::Unwrap<Context>(args[0]->ToObject()));

            Handle<Object> instH = ((Function*)(*args.Data()))->NewInstance();
            XnNodeHandle handle;
            Create(ctx, handle, NULL);
            (new GestureGenerator(handle))->Wrap(instH); //FIXME: should we use WrapperUtils wrap()?

            return instH;

        } catch (Handle<Value> err) {return ThrowException(err);}
    }

}
