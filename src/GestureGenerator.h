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

#ifndef NODE_XN_GESTURE_GENERATOR_H
#define	NODE_XN_GESTURE_GENERATOR_H

#include "wrapperUtils.h"

#include "Generator.h"

namespace node_xn {

    using namespace v8;
    using namespace node;

    class GestureGenerator: public Generator {
    public:
        /* Factory method(s) */
        static void create(const Context& ctx, XnNodeHandle& handle, XnNodeQuery* query);

        /* Copy ctor. */
        inline GestureGenerator(const GestureGenerator& orig) : Generator(orig) {}

        /** WRAPPED METHODS **/
        static Handle<Value> createGestureGeneratorSync(const Arguments& args);
    protected:
        /* Supertype constructors */
        inline GestureGenerator(XnNodeHandle handle) : Generator(handle) {}
        inline GestureGenerator(const ProductionNode& orig) : Generator(orig) {}
    };

    /* Initializer */
    Persistent<FunctionTemplate> INIT_GestureGenerator(Handle<Object> ctx, Persistent<FunctionTemplate> parent);
}

#endif	/* NODE_XN_GESTURE_GENERATOR_H */
