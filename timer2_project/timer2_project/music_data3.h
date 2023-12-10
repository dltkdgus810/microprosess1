/*
 * ----------------------------------------------------------------------------
 *          Music data (±è´ÞÈñ)
 * ----------------------------------------------------------------------------
 */

#ifndef MUSIC_H
#define MUSIC_H

#include "musical_notes.h"

uint8_t music_tempo = 55;

uint16_t m_notes[] = 
                    {HF, HDX, HF, 
					 HCX, MGX, XX, HF, HDX, HF, HCX, MGX, XX, XX, HCX, HCX, HC, HCX, HC, HCX, HF, HDX, XX, HFX, HF, HFX,
					 HDX, HC, XX, HFX, HF, HFX, HDX, HC, XX,  HGX, HAX, HGX, XX, HGX, HFX, HF, HDX, HCX, XX
                    };
                    
uint8_t m_duration[] = 
                    {E, E, E,
					 (Q+E),S, Q, E, E, E, (Q+E), E, Q, E, E,E,E, E,E,E,E,H,Q,E,E,E,
					 (Q+E), E, Q, E,E,E, (Q+E), E, Q, E,E,E,1,E,E,E,E,E, H
                    };
#endif
