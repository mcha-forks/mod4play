//----------------------------------------------------------------------------
//  Mod4Play IT/S3M/XM/MOD/FT Module Replayer
//----------------------------------------------------------------------------
//
// BSD 3-Clause License
//
// Copyright (c) 2023-2025, dashodanger
// Copyright (c) 2020-2021, Olav Sørensen
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdint.h>

//-----------------------------------------------------------------------------------
// 							Enumerations - Mod4Play
//-----------------------------------------------------------------------------------

enum m4p_format
{
    M4P_FORMAT_UNKNOWN = 0,
    M4P_FORMAT_IT_S3M  = 1,
    M4P_FORMAT_XM_MOD  = 2
};

typedef struct it_state_t it_state_t;
typedef struct ft_state_t ft_state_t;

typedef struct {
    enum m4p_format current_format;
    union {
        it_state_t *it_state;
        ft_state_t *ft_state;
    };
} m4p_state_t;

//-----------------------------------------------------------------------------------
// 							Implementation - Mod4Play
//-----------------------------------------------------------------------------------

// See if song in memory is a supported type (IT/S3M/XM/MOD)
int m4p_TestFromData(const uint8_t *Data, uint32_t DataLen);

// Load song from memory and initialize appropriate replayer
bool m4p_LoadFromData(m4p_state_t *state, const uint8_t *Data, uint32_t DataLen, int32_t mixingFrequency);

// Set replayer status to Play (does not generate output)
void m4p_PlaySong(m4p_state_t state);

// Generate samples and fill buffer
int m4p_GenerateSamples(m4p_state_t state, int16_t *buffer, int32_t numSamples);

// Generate samples and fill buffer
int m4p_GenerateFloatSamples(m4p_state_t state, float *buffer, int32_t numSamples);

// Set replayer status to Stop
void m4p_Stop(m4p_state_t state);

// De-initialize replayer
void m4p_Close(m4p_state_t state);

// Free song memfile
void m4p_FreeSong(m4p_state_t state);

#ifdef __cplusplus
}
#endif
