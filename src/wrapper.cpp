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

#include <v8.h>
#include <node.h>

#include "Context.h"
#include "ProductionNode.h"
#include "Generator.h"

namespace node_xn {

    using namespace v8;
    using namespace node;

    extern "C" {

        static void init(Handle<Object> module) {
            //Declare global objects (version, ...)
            //TODO

            //Initialize every exposed class
            Persistent<FunctionTemplate> context = Context::INIT(module);
            Persistent<FunctionTemplate> prod_node = ProductionNode::INIT(module);
            Persistent<FunctionTemplate> generator = Generator::INIT(module, prod_node);
        }

        /** Finally, let Node.JS know about our module **/
        NODE_MODULE(openni, init);
    }

}
