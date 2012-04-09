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

#ifndef NODE_XN_PRODUCTION_NODE_H
#define	NODE_XN_PRODUCTION_NODE_H

#include "wrapperUtils.h"

namespace node_xn {

    using namespace v8;
    using namespace node;
    
    class ProductionNode: public ObjectWrap {
    public:
        /* Core methods */
        inline ProductionNode(XnNodeHandle const handle) : ptr(handle) {OnConstruct();}
        ~ProductionNode();
        
        /* Copy ctor. */
        inline ProductionNode(const ProductionNode& orig) : ptr(orig.ptr) {OnConstruct();}
        
        /** WRAPPED METHODS **/
    private:
        void OnConstruct();
        XnNodeHandle const ptr;
    };

    /* Initializer */
    Persistent<FunctionTemplate> INIT_ProductionNode(Handle<Object> ctx);
}

#endif	/* NODE_XN_PRODUCTION_NODE_H */
