/*
 * ----------------------------------------------------------------------------
 *          Music data
 * ----------------------------------------------------------------------------
 */

#ifndef MUSIC_H
#define MUSIC_H

#include "musical_notes.h"

uint8_t music_tempo = 95;

uint16_t m_notes[] = 
                    {HC, MG, HD, HC, XX, HC, XX, HC, HD, HE, XX, HE, HF, MA, HC, HD, MB, HC, MB, 
                     MA, MG, XX, ME, MB, HC, ME, MG, MA, HC, MA, MG,
                     HC, MG, HD, HC, XX, HC, XX, HC, HD, HE, XX, HE, HF, MA, HC, HD, XX, HD, HE, HD, HC,
                     HC, XX, MB, MA, XX, MA, XX, MA, MB, HC, HD, HE, HF,
                     HG, XX, HG, XX, HG, XX, HG, XX, HG, HF, XX, HF, HE, XX, HE, XX, HD, HE, XX, HE,
                     HF, XX, HF, XX, HF, HE, HF, HE, HD, HC, XX, HC, HD, XX, HD, HE, HF,
                     HG, XX, HG, XX, HG, XX, HG, XX, HG, HF, XX, HF, HE, XX, HE, HCX, HD, XX, HD, HE, XX, HE,
                     HF, XX, HF, XX, HF, HE, HF, HE, HD, HC, HG, XX,
                     XX, MG, HC, HD, XX, HD, HE, XX, HE, XX, HE, XX, HE, HF, HE, HD, HC, HD,
                     XX, HD, HE, HF, HE, MB, MAX, MB, HD, HC, XX, HC, MB, MA, HA, HE, HD, HC,
                     HD, HE, HF, XX, HF, HG, XX, HG, XX, HG, XX, HG, XX, HG, HF, XX, HF, HE, HA,
                     XX, HG, HF, HE, XX, HE, HF, XX, HF, HE, HF, XX, HE, XX,
                     HE, HF, XX, HF, XX, HF, XX, HF, HE, HD, HC, HD, MB, HC
                    };
                    
uint8_t m_duration[] = 
                    {E, E, E, S, 1, Q, 1, S, E, E, 1, E, E, E, S, Q, S, E, E, 
                     S, (E+S), (E+S), S, E, E, E, S, (S+Q+E), S, (S+Q), Q,
                     E, E, E, S, 1, Q, 1, S, E, E, 1, E, E, E, S, Q, 1, S, E, S, S,
                     Q, (E+S), S, E, 1, E, 1, E, S, S, (H+Q), E, E,
                     E, 1, E, 1, E, 1, S, 1, (E+S), E, 1, E, S, 1, (S+Q), Q, (E+S), S, 1, Q,
                     E, 1, E, 1, E, S, (S+E), E, E, S, 1, (S+E+Q), S, 1, (S+Q), E, E,
                     E, 1, E, 1, E, 1, S, 1, (S+E), E, 1, E, S, 1, (S+Q), (E+S), S, 1, (E+S), S, 1, Q,
                     E, 1, E, 1, E, S, (E+S), E, E, S, (S+H+Q), Q,
                     E, E, E, E, 1, E, S, 1, (S+E), 1, S, 1, S, E, E, E, S, (S+Q),
                     E, S, S, E, E, E, E, E, (E+S), S, 1, (E+S), S, E, E, E, E, E,
                     H, (E+S), S, 1, Q, E, 1, E, 1, E, 1, S, 1, (S+E), E, 1, E, S, (S+H),
                     E, E, E, E, 1, E, E, 1, E, S, (S+Q), (E+S), S, 1,
                    (E+S), S, 1, E, 1, S, 1, Q, (S+E), S, S, E, S, (S+H)
                    };
#endif
