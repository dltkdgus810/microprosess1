/*
 * ----------------------------------------------------------------------------
 *              Frequencies of musical notes
 * ----------------------------------------------------------------------------
 */

#ifndef MUSICAL_NOTES_H
#define MUSICAL_NOTES_H

// frequency values of musical notes
#ifdef SOUND_PWM
#define XX      0
#define LA      1731             
#define LAX     1634 
#define LB      1541    // low B (si)
#define MC      1453    // middle C (Do)
#define MCX     1374  
#define MD      1295    // Re
#define MDX     1224 
#define ME      1153    // Mi
#define MF      1091    // Fa
#define MFX     1029 
#define MG      971     // Sol
#define MGX     917  
#define MA      865     // La
#define MAX     816  
#define MB      770     // Si
#define HC      727     // high C (Do)
#define HCX     687  
#define HD      648  
#define HDX     611  
#define HE      577  
#define HF      545  
#define HFX     514  
#define HG      485  
#define HGX     457  
#define HA      432  

#else
#define XX      0
#define LA      220            
#define LAX     233
#define LB      247     // low B (si)
#define MC      262     // middle C (Do)
#define MCX     277 
#define MD      294     // Re
#define MDX     311
#define ME      330     // Mi
#define MF      349     // Fa
#define MFX     370
#define MG      392     // Sol
#define MGX     415
#define MA      440     // La
#define MAX     466
#define MB      494     // Si
#define HC      523     // high C (Do)
#define HCX     554
#define HD      587
#define HDX     622
#define HE      659
#define HF      698
#define HFX     740
#define HG      784
#define HGX     831
#define HA      880
#define HAX		932		
#define HB		987		
#endif

#define L		32		// 온음표
#define H       16      // 2분 음표
#define HQ		12		// 점 4분 음표
#define Q       8       // 4분 음표
#define E       4       // 8분 음표
#define S       2       // 16분 음표

#endif

