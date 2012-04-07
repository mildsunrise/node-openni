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

#ifndef NODE_XN_CONTEXT_H
#define	NODE_XN_CONTEXT_H

#include "wrapperUtils.h"

namespace node_xn {

    using namespace v8;
    using namespace node;

    class Context: public ObjectWrap {
    public:
        /* Factory method(s) */
        static Context Init();

        /* Core methods */
        inline Context(XnContext* const handle) : ptr(handle) {OnConstruct();}
        ~Context();

        /* Copy ctor. */
        inline Context(const Context& orig) : ptr(orig.ptr) {OnConstruct();}
        inline Context operator=(const Context& orig) {return Context(orig);}

        /** WRAPPED METHODS **/
        static void INIT(Handle<Object> ctx);
        static Handle<Value> initSync(const Arguments& args);
    private:
        XnContext* const ptr;
        void OnConstruct();
    };

}

#endif	/* NODE_XN_CONTEXT_H */
