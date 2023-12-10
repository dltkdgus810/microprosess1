/*
 * ----------------------------------------------------------------------------
 *          Music data (±è´ÞÈñ)
 * ----------------------------------------------------------------------------
 */

#ifndef MUSIC_H
#define MUSIC_H

#include "musical_notes.h"

uint8_t music_tempo = 95;

const uint16_t m_notes[] = 
                    {MG, MB, MD, MA, MB, MA, ME, MG, XX, 
					 MG, MB, MA, MG, HE, HD, HE, MB, HD, HE, MB, MA,
					 MG, MB, MD, MA, MB, MA, ME, MG, 
					 MG, MG, MG, MG, MB, MA, MG, HE, HD, HE, MB, HD, HE, MB, MA,
					 HC, HC, HC, HC, HC, HD, HE, HD, MG, MA,
					 HC, HC, HC, HC, HC, HC, HD, HE, HD, HD, MB, MA,
					 ME, MG, MG, XX, ME, MFX, MG, MA, ME, MFX, MG, MG, MG, MA, ME, XX,
					 MB, MB, MB, MB, MB, XX, MG, MG, MA, MB, MG, MG,
					 ME, MFX, MG, XX, ME, MFX, MG, MG, XX, ME, MFX, MG, MG, MA, ME, XX,
					 MA, MB, MB, MB, MB, MB, MB, MG, MG, HC, HD, HC, HC, XX, XX
                    };
                    
const uint8_t m_duration[] = 
                    {E, Q, E, E, E, E, E, H, (S+E), 
					 S, S, S, E, S, S, Q, E, Q, E, E, (H+H),
					 E, Q, E, E, E, E, E, H,
					 S, S, S, S, S, S, E, S, S, Q, E, Q, E, E, (H+H),
					 S, S, S, S, E, E, E, Q, E, (H+H),
					 S, S, S, S, E, S, S, E, S, (S+E), E, (H+H),
					 S, S, E, E, S, S, E, (Q+E), S, S, S, S, E, S, (S+Q), (S+E), 
					 S, Q, S, E, E, Q, E, S, S, S, S, S, (S+H+Q),
					 S, S, E, E, S, S, S, (S+E), E, S, S, Q, E, S, (S+Q), (S+E), 
					 S, E, E, E, S, (S+E), Q, S, S, S, S, S, (S+Q+H), Q, Q
                    };
#endif
