//
//  solitaireFunction.h
//  Solitaire
//
//  Created by 이재원 on 28/05/2019.
//  Copyright © 2019 Jae Won. All rights reserved.
//

#ifndef solitaireFunction_h
#define solitaireFunction_h

#include <stdio.h>
#include "card.h"

makeCardAndPutToStock();
mixStock();
dealCards(); //mix and deal cards to stock, playArea.
showCurBoard(); //drawing current board
getMove(); //get Movement command from user
printMovErrorMessage(); //print movement can't be allowed.
moveCard(); // move cards according to user's comand.


#endif /* solitaireFunction_h */
