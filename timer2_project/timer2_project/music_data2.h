/*
 * ----------------------------------------------------------------------------
 *          Music data (±è´ÞÈñ)
 * ----------------------------------------------------------------------------
 */

#ifndef MUSIC_H
#define MUSIC_H

#include "musical_notes.h"

uint8_t music_tempo = 75;

uint16_t m_notes[] = 
                    {/*HG, HE, HF, HG, HE, HF, HG, MG, MA, MB, HC, HD, HE, HF, HE, HC, HD, HE, ME, MF, MG, MA, MG, MF, MG, ME, MF, MG, MF, MA, MG, MF, ME, MD, ME, MD, MC, MD, ME, MF, MG, MA,
                       MF, MA, MG, MA, MB, HC, MG, MA, MB, HC, HD, HE, HF, HG, HE, HC, HD, HE, HD, HC, HD, MB, HC, HD, HE, HD, HC, MB, HC, MA, MB, HC, MC, MD, ME, MF, ME, MD, ME, HC, MB, HC, 
                       MA, HC, MB, MA, MG, MF, MG, MF, ME, MF, MG, MA, MB, HC, MA, HC, MB, HC, MB, MA, MB, HC, HD, HC, MB, HC, MA, MB, HC, ME, MD, MG, MD, ME, MC, HC, MB, MA, MB, HE, HG, HA,
                       HF, HE, HD, HF, HE, HD, HC, MB, MA, MG, MF, ME, MD, MF, ME, MD, MC,MD, ME, MF, MG, MC, MG, MF, ME, MA, MG, MF, MG, MF, ME, MD, MC, MF, MA, MB, HC, MB, MA, MG, MF, ME, MD, MA, MG, MA,
                       MB, HD, */ HG, HE, HF, HG, HE, HF, HG, MG, MA, MB, HC, HD, HE, HF, HE, HC, HD, HE, ME, MF, MG, MA, MG, MF, MG, ME, MF, MG, MF, MA, MG, MF, ME, MD,
                       ME, MD, MC, MD, ME, MF, MG, MA, MF, MA, MG, MA, MB, HC, MG, MA, MB, HC, HD, HE, HF, HG, HE, HC, HD, HE, HD, HC, HD, MB, HC, HD, HE, HD, HC, MB, HC, MA, MB, HC, MC, MD,
                       ME, MF, ME, MD, ME, HC, MB, HC, MA, HC, MB, MA, MG, MF, MG, MF, ME, MF, MG, MA, MB, HC, MA, HC, MB, HC, MB, MA, MB, HC, HD, HC, MB, HC, MA, MB, HC, HC, HD, HE, HC,
                       MB, MB, HC, HD, MB, HC, MA, MB, HC, MA, MB, HG, HF, HE, HD, HC, HF, HE, HD, HF, HE, HC, HD, HE, HG, HF, HA, HG, HF, HE,
                       HD, HG, HF, HE, HD, ME, HC, MB, HC, ME, MG, MB, HC, HD, MB, MA, HC, HD, HE, HC, HE, HE, HD, HC, MB, MA, MA, MG, MA, MB,
                       HC, HE, HD, HC, HE, HF, HC, MB, MA, MA, MG, MD, MG, MG, HG, HE, HF, HG, HE, HF, HG, MG, MA, MB, HC, HD, HE, HF, HE, HC, HD, HE, ME, MF,
                       MG, MA, MG, MF, MG, ME, MF, MG, MF, MA, MG, MF, ME, MD, ME, MD, MC, MD, ME, MF, MG, MA, MF, MA, MG, MA, MB, HC, MB, HC, HD, HC, MB, HC, MA, MB, HC
                    };
                    
uint8_t m_duration[] = 
                    {/*E, S, S, E, S, S, S, S, S, S, S, S, S, S, E, S, S, E, S, S, S, S, S, S, S, S, S, S, E, S, S, E, S, S, S, S, S, S, S, S, S, S, 
                       E, S, S, E, S, S, S, S, S, S, S, S, S, S, E, S, S, E, S, S, S, S, S, S, S, S, S, S, E, S, S, E, S, S, S, S, S, S, S, S, S, S, 
                       E, S, S, E, S, S, S, S, S, S, S, S, S, S, E, S, S, E, S, S, S, S, S, S, S, S, S, S, (Q+E), E, E, E,E, E, E,E, E, E,E, E, E,E,
                       E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, E, Q, Q,
                       Q,Q,*/E, S, S, E, S, S, S, S, S, S, S, S, S, S, E, S, S, E, S, S, S, S, S, S, S, S, S, S, E, S, S, E, S, S, 
                       S, S, S, S, S, S, S, S, E, S, S, E, S, S, S, S, S, S, S, S, S, S,E, S, S, E, S, S, S, S, S, S, S, S, S, S,E, S, S, E, S, S, 
                       S, S, S, S, S, S, S, S, E, S, S, E, S, S, S, S, S, S, S, S, S, S,E, S, S, E, S, S, S, S, S, S, S, S, S, S, E, S, S, E, E,
                       E, S, S, E, E, E, S, S, E, E, E, S, S, E, E, E, S, S, E, E, E, S, S, E, E, E, S, S, E, E,
                       E, S, S, E, E, E, S, S, E, E, E, S, S, E, E, E, S, S, E, E, E, S, S, E, E, E, S, S, E, E,
                       E, S, S, E, E, E, S, S, E, E, E, E, E, E, E, S, S, E, S, S, S, S, S, S, S, S, S, S, E, S, S, E, S, S,
                       S, S, S, S, S, S, S, S, E, S, S, E, S, S, S, S, S, S, S, S, S, S, E, S, S, E, S, S, S, S, S, S, S, S, S, S, H
                    };                   
#endif
