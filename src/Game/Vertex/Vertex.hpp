/*
** Clone Game Virgile
*/

#pragma once

#include "required.hpp"
#include <SDL2/SDL_opengl.h>
#include <memory>

namespace Game {
    typedef struct vertexData_s {
        float x;
        float y;
        float z;
        // texture...
    } vertexData_t;

    class Vertex {
        public:
            enum specificDataSize {
                POSITION,
            };

            Vertex(const vertexData_t *arr, const ::GLuint *indices, const size_t &dataSize, const size_t &arrSize, const size_t &indicesSize);
            Vertex(const Vertex &mod);
            Vertex &operator = (const Vertex &mod);
            ~Vertex();

            inline std::unique_ptr<vertexData_t[]> &getData()
            {
                return (this->__data);
            }

            inline std::unique_ptr<::GLuint[]> &getIndices()
            {
                return (this->__indices);
            }

            inline size_t getDataBytes() const
            {
                return (this->__dataSize * sizeof(vertexData_t));
            }

            size_t getSpecificDataSize(const specificDataSize &data) const;

            inline size_t getIndicesBytes() const
            {
                return (this->__indicesSize * sizeof(::GLuint));
            }

            inline size_t getIndicesSize() const
            {
                return (this->__indicesSize);
            }
            
            inline size_t getDataArrSize() const
            {
                return (this->__dataArrSize);
            }
       
            inline size_t getPoints() const
            {
                return (this->__dataSize);
            }
        protected:
        private:

            template <typename T>
            void __copyArray(T *src, const T *dest, const size_t &size) const
            {
                for (size_t i = 0; i < size; i++) {
                    src[i] = dest[i];
                }
            }

            template <typename T>
            void __copyArray(T *src, T *dest, const size_t &size) const
            {
                for (size_t i = 0; i < size; i++) {
                    src[i] = dest[i];
                }
            }

            std::unique_ptr<vertexData_t[]> __data;
            std::unique_ptr<::GLuint[]> __indices;
            size_t __dataSize;
            size_t __dataArrSize;
            size_t __indicesSize;
    };
};
