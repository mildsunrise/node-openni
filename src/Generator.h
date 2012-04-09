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

#ifndef NODE_XN_GENERATOR_H
#define	NODE_XN_GENERATOR_H

#include "wrapperUtils.h"

#include "ProductionNode.h"

namespace node_xn {

    using namespace v8;
    using namespace node;
    
    class Generator: public ProductionNode {
    public:
        /* Copy ctor. */
        inline Generator(const Generator& orig) : ProductionNode(orig) {}
        
        /** WRAPPED METHODS **/
        static Persistent<FunctionTemplate> INIT(Handle<Object> ctx, Persistent<FunctionTemplate> parent);
    protected:
        /* Supertype constructors */
        inline Generator(XnNodeHandle handle) : ProductionNode(handle) {}
        inline Generator(const ProductionNode& orig) : ProductionNode(orig) {}
    };

}

#endif	/* NODE_XN_GENERATOR_H */
