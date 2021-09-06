/*
** CloneGame Virgile AGNEL
*/

#pragma once

#include "required.hpp"
#include "../../Blocks/Blocks.hpp"

namespace Game {
    class ObjectBuilder {
        public:
            ObjectBuilder();
            ~ObjectBuilder() = default;

            // TODO put object poperties into a class or a struct
            std::unique_ptr<IGameObject> createObject(const std::string &name, const GameObjectInfo &info, const std::string &vPath, const std::string &fPath, const Vertex &vertex);
        protected:
        private:
            std::unique_ptr<IGameObject> __createBlocks(const std::string &name, const GameObjectInfo &info, const std::string &vPath, const std::string &fPath, const Vertex &vertex) const;

            std::map<GameObjectInfo, std::function<std::unique_ptr<IGameObject>(const ObjectBuilder &, const std::string &, const GameObjectInfo &, const std::string &, const std::string &, const Vertex &)>> __fctMap;
    };
}
