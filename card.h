//
//  card.h
//  Solitaire
//
//  Created by 이재원 on 28/05/2019.
//  Copyright © 2019 Jae Won. All rights reserved.
//

#ifndef card_h
#define card_h

typedef enum{
    heart, diamond, clover, spade
}shape;

typedef enum{
    A = 1, two, three, four, five, six, seven, eight, nine, ten, J, Q, K
}allowedNum;

typedef enum{
    True = 1, False = 0
}boolean;

typedef struct{
    shape shp;
    allowedNum num;
    boolean faceUp;
}card;

#endif /* card_h */
