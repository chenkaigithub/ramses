//  -------------------------------------------------------------------------
//  Copyright (C) 2014 BMW Car IT GmbH
//  -------------------------------------------------------------------------
//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at https://mozilla.org/MPL/2.0/.
//  -------------------------------------------------------------------------

// API
#include "ramses-client-api/SplineLinearVector2i.h"

// internal
#include "SplineImpl.h"

namespace ramses
{
    SplineLinearVector2i::SplineLinearVector2i(SplineImpl& pimpl)
        : Spline(pimpl)
    {
    }

    SplineLinearVector2i::~SplineLinearVector2i()
    {
    }

    status_t SplineLinearVector2i::setKey(splineTimeStamp_t timeStamp, int32_t x, int32_t y)
    {
        const status_t status = impl.setSplineKeyLinearVector2i(timeStamp, x, y);
        LOG_HL_CLIENT_API3(status, timeStamp, x, y);
        return status;
    }

    status_t SplineLinearVector2i::getKeyValues(splineKeyIndex_t keyIndex, splineTimeStamp_t& timeStamp, int32_t& x, int32_t& y) const
    {
        return impl.getSplineKeyVector2i(keyIndex, timeStamp, x, y);
    }
}
