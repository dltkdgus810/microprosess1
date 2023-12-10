/*
 * ----------------------------------------------------------------------------
 *          Music data (À±ÅÂÈ£)
 * ----------------------------------------------------------------------------
 */

#ifndef MUSIC_H
#define MUSIC_H

#include "musical_notes.h"

uint8_t music_tempo = 57;

uint16_t m_notes[] = 
                    {HFX, HE, HFX, HE, HD, HE, HFX, HFX, HE, HD, MB, HD, MB, MA, XX,
					 XX, HD, HD, HD, HE, XX, HFX, HFX, HFX, HE, HFX, HE, HFX, HE, HD, XX,
					 MFX, MA, MA, MA, MA, MB, MA, MA, XX, MB, HD, HD, HD, HD, HE, HD, HD, HD, HE,
					 HE, HFX, HFX, HFX, HFX, HE, HD, XX, HD, HD, HE, HFX, HE, HE, HE, XX,
					 HFX, HFX, HFX, HFX, HFX, HE, HFX, HE, HD, XX, HE, HFX, HFX, HE, HD, MB, MA, MA, XX,
					 XX, HD, HD, HD, HD, MB, MA, MB, MA, MA, MFX, ME, MFX, ME, MD, XX,
					 XX, HE, HE, HE, XX, HE, HD, HE, HE, HFX, HFX, HFX, HFX, HE, HFX, HE, HD,
					 XX, HE, HFX, HFX, HFX, HE, HD, XX, HD, HD, HE, HE, HFX, HE, HE, XX, 
					 XX, HA, HA, HA, HA, HFX, HE, HFX, HE, HD, HD, HD, HE, HFX, HE, HD, MB, HD, MB, MA, XX,
					 XX, HE, HE, HE, HE, HE, HFX, HA, HB, HA, HA, HFX, HE, HFX, HE, HD, HD
                    };
                    
uint8_t m_duration[] = 
                    {L, HQ, S, S, H, E, E, E, E, Q, S, S, E, H, Q,
					 HQ, E, Q, E, E, E, E, E, E, Q, E, S, S, S, L, L,
					 Q, E, E, E, E, E, E, H, HQ, Q, E, E, E, E, E, E, H, E, HQ,
					 E, E, E, E, Q, E, E, E, Q, E, Q, E, E, L, H, Q,
					 Q, E, E, E, E, S, S, E, H, Q, E, E, E, E, Q, E, E, H, Q,
					 Q, E, E, E, E, Q, Q, E, E, E, E, S, S, E, L, L,
					 E, E, E, HQ, E, HQ, E, HQ, E, E, E, E, Q, S, S, E, L,
					 Q, E, E, E, E, E, E, E, E, Q, Q, E, E, L, H, Q,
					 E, E, E, E, Q, E, E, H, E, E, E, E, E, E, E, E, S, S, E, H, Q,
					 Q, E, E, E, E, E, E, Q, E, E, E, E, S, S, E, L , L
                    };                   
#endif
