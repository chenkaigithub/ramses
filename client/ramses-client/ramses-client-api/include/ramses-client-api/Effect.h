//  -------------------------------------------------------------------------
//  Copyright (C) 2014 BMW Car IT GmbH
//  -------------------------------------------------------------------------
//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at https://mozilla.org/MPL/2.0/.
//  -------------------------------------------------------------------------

#ifndef RAMSES_EFFECT_H
#define RAMSES_EFFECT_H

#include "ramses-framework-api/RamsesFrameworkTypes.h"
#include "ramses-client-api/Resource.h"
#include "ramses-client-api/EffectInputSemantic.h"

namespace ramses
{
    class UniformInput;
    class AttributeInput;

    /**
     * @brief An effect describes how an object will be rendered to the screen.
    */
    class RAMSES_API Effect : public Resource
    {
    public:

        /**
        * @brief Gets number of uniform inputs.
        *
        * @return Number of uniform inputs
        */
        uint32_t getUniformInputCount() const;

        /**
        * @brief Gets number of attribute inputs.
        *
        * @return Number of attribute inputs
        */
        uint32_t getAttributeInputCount() const;

        /**
        * @brief Gets uniform input at given index.
        *
        * @param[in] index Index of uniform input to retrieve
        * @param[out] uniformInput Uniform input
        * @return StatusOK for success, otherwise the returned status can be used
        *         to resolve error message using getStatusMessage().
        */
        status_t getUniformInput(uint32_t index, UniformInput& uniformInput) const;

        /**
        * @brief Gets attribute input at given index.
        *
        * @param[in] index Index of attribute input to retrieve
        * @param[out] attributeInput Attribute input
        * @return StatusOK for success, otherwise the returned status can be used
        *         to resolve error message using getStatusMessage().
        */
        status_t getAttributeInput(uint32_t index, AttributeInput& attributeInput) const;

        /**
        * @brief Finds uniform input by input name.
        *
        * @param[in] inputName Name of uniform input to retrieve
        * @param[out] uniformInput Uniform input
        * @return StatusOK for success, otherwise the returned status can be used
        *         to resolve error message using getStatusMessage().
        */
        status_t findUniformInput(const char* inputName, UniformInput& uniformInput) const;

        /**
        * @brief Finds attribute input by input name.
        *
        * @param[in] inputName Name of attribute input to retrieve
        * @param[out] attributeInput Attribute input
        * @return StatusOK for success, otherwise the returned status can be used
        *         to resolve error message using getStatusMessage().
        */
        status_t findAttributeInput(const char* inputName, AttributeInput& attributeInput) const;

        /**
        * @brief Finds uniform input that represents a semantic input (if existing).
        *
        * @param[in] uniformSemantic Semantic of uniform input to retrieve
        * @param[out] uniformInput Uniform input
        * @return StatusOK for success, otherwise the returned status can be used
        *         to resolve error message using getStatusMessage().
        */
        status_t findUniformInput(EEffectUniformSemantic uniformSemantic, UniformInput& uniformInput) const;

        /**
        * @brief Finds attribute input that represents a semantic input (if existing).
        *
        * @param[in] attributeSemantic Semantic of attribute input to retrieve
        * @param[out] attributeInput Attribute input
        * @return StatusOK for success, otherwise the returned status can be used
        *         to resolve error message using getStatusMessage().
        */
        status_t findAttributeInput(EEffectAttributeSemantic attributeSemantic, AttributeInput& attributeInput) const;

        /**
        * @brief Stores internal data for implementation specifics of Effect.
        */
        class EffectImpl& impl;

    protected:
        /**
        * @brief RamsesClient is the convenience library for application developers
        */
        friend class RamsesClientImpl;

        /**
        * @brief Constructor of Effect
        *
        * @param[in] pimpl Internal data for implementation specifics of Effect (sink - instance becomes owner)
        */
        explicit Effect(EffectImpl& pimpl);

        /**
        * @brief Copy constructor of Effect
        *
        * @param[in] other Other instance of Effect class
        */
        Effect(const Effect& other);

        /**
        * @brief Assignment operator of Effect.
        *
        * @param[in] other Other instance of Effect class
        * @return This instance after assignment
        */
        Effect& operator=(const Effect& other);

        /**
        * @brief Destructor of the Effect
        */
        virtual ~Effect();
    };
}

#endif
