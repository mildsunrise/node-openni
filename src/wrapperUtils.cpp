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

#include "wrapperUtils.h"

#include <sstream>

namespace node_xn {

    using namespace v8;
    using namespace node;

    //wrap

    void check(XnStatus status) {
        if (status == XN_STATUS_OK) return;

        throw Exception::Error(v8::String::New(xnGetStatusString(status))); //TODO
    }

    void checkArgumentsLen(const Arguments& args, const int min) {
        const int len = args.Length();
        if (len >= min) return;

        const char* mmsg = " arguments";
        if (min == 1) mmsg = " argument";

        const char* lmsg = " were";
        if (len == 1) lmsg = " was";

        std::stringstream msg;
        msg << "Function needs " << min << mmsg << ", but " << len << lmsg << " provided.";

        throw Exception::TypeError(v8::String::New(msg.str().data()));
    }

    //checkValid

    Handle<Value> new_default(const Arguments& args) {
        HandleScope scope;
        return args.This();
    }

}
