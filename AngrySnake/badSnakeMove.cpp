
if(badSnake.getFirstSegmX() < moiSnake.getLastSegmX())
{
    if(badSnake.nextPxlIs(10,' ','d') || badSnake.nextPxlIs(30,'@','d') || badSnake.nextPxlIs(foodclr,foodtxt,'d'))
        badSnake.setFacing('d');

    else
        if(badSnake.nextPxlIs(10,' ','s') || badSnake.nextPxlIs(30,'@','w') || badSnake.nextPxlIs(foodclr,foodtxt,'w'))
            badSnake.setFacing('w');
        else
            if(badSnake.nextPxlIs(10,' ','w') || badSnake.nextPxlIs(30,'@','a') || badSnake.nextPxlIs(foodclr,foodtxt,'a'))
                badSnake.setFacing('s');

}
    else
if(badSnake.getFirstSegmX() > moiSnake.getLastSegmX())
{
    if(badSnake.nextPxlIs(10,' ','a') || badSnake.nextPxlIs(30,'@','a') || badSnake.nextPxlIs(foodclr,foodtxt,'a'))
        badSnake.setFacing('a');

    else
        if(badSnake.nextPxlIs(10,' ','s') || badSnake.nextPxlIs(30,'@','w') || badSnake.nextPxlIs(foodclr,foodtxt,'w'))
            badSnake.setFacing('w');
        else
            if(badSnake.nextPxlIs(1212,' ','w') || badSnake.nextPxlIs(30,'@','s') || badSnake.nextPxlIs(foodclr,foodtxt,'s'))
                badSnake.setFacing('s');

}
    else
if(badSnake.getFirstSegmY() < moiSnake.getLastSegmY())
{
    if(badSnake.nextPxlIs(10,' ','w') || badSnake.nextPxlIs(30,'@','s') || badSnake.nextPxlIs(foodclr,foodtxt,'s'))
        badSnake.setFacing('s');

    else
        if(badSnake.nextPxlIs(10,' ','a') || badSnake.nextPxlIs(30,'@','a') || badSnake.nextPxlIs(foodclr,foodtxt,'a'))
            badSnake.setFacing('a');
        else
            if(badSnake.nextPxlIs(10,' ','d') || badSnake.nextPxlIs(30,'@','d') || badSnake.nextPxlIs(foodclr,foodtxt,'d'))
                badSnake.setFacing('d');

}
    else
if(badSnake.getFirstSegmY() > moiSnake.getLastSegmY())
{
    if(badSnake.nextPxlIs(10,' ','s') || badSnake.nextPxlIs(30,'@','w') || badSnake.nextPxlIs(foodclr,foodtxt,'w'))
        badSnake.setFacing('w');

    else
        if(badSnake.nextPxlIs(10,' ','d') || badSnake.nextPxlIs(30,'@','a') || badSnake.nextPxlIs(foodclr,foodtxt,'a'))
            badSnake.setFacing('a');
        else
            if(badSnake.nextPxlIs(10,' ','a') || badSnake.nextPxlIs(30,'@','d') || badSnake.nextPxlIs(foodclr,foodtxt,'d'))
                badSnake.setFacing('d');

}

