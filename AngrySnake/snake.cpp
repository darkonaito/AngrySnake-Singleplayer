class Snake
{
public:
    Snake(short x,short y,short color,char txt,char facing,Grid& grid);

    bool addSegm(short n = 1);
    bool subSegm(short n = 1);

    void move(char dir = '1');

    void draw();

    void clear(short bcolor,char btxt);

    void setFacing(char facing) {this->facing = facing;}

    char getFacing() {return this->facing;}

    short getLength() {return length;}

    bool nextPxlIs(short color,char txt,char facing_ = '1');

    short getLastSegmX() {return body[length - 1].getX();}
    short getLastSegmY() {return body[length - 1].getY();}

    short getFirstSegmX() {return body[0].getX();}
    short getFirstSegmY() {return body[0].getY();}


    Point getLastSegmCoord () {return body[length - 1];}
    Point getFirstSegmCoord () {return body[0];}

private:
    Grid&  grid;
    Point body[50];

    short  length;
    char   facing;
    short  color;
    char   txt;
    short  backclr;
    char   backtxt;
};

bool Snake::addSegm(short n)   //{length += n; for(short i = length; i > 2; i-- ) {body[i - 1] = body[i - 2];}}
{
    if((length + n) < 50) this->length += n;
    else return false;

    for(short i = this->length; (i >= (this->length - n) && i > 1); i--)
    {
        Beep(53,30);
        Beep(347,45);
        this->body[i - 1] = this->body[i - 2];
        Beep(193,15);
    }

    return true;
}

bool Snake::subSegm(short n)   //{length += n; for(short i = length; i > 2; i-- ) {body[i - 1] = body[i - 2];}}
{
    if(length > 1) this->length -= n;
    else return false;

    for(short i = this->length; (i >= (this->length - n) && i > 1); i--)
    {
        this->body[i - 1] = this->body[i - 2];
    }

    return true;
}

Snake::Snake(short x,short y,short color,char txt,char facing,Grid& grid)
:
    length(1),
    color(color),
    grid(grid),
    txt(txt)
{
    body[0] = Point(x, y);
}

void Snake::move(char dir)
{
    if(dir == '0') return;
    if(dir == '1') dir = this->facing;

    for(short i = length - 1; i > 0; i--)
    {
        body[i] = body[i-1];
    }


    if(dir == 'w')  body[0].decrsY();
    if(dir == 'a')  body[0].decrsX();
    if(dir == 's')  body[0].incrsY();
    if(dir == 'd')  body[0].incrsX();
}

void Snake::draw()
{
    for(short i = 0; i < length; i++)
    {
        grid.drawpnt(body[i],color,txt);
    }
}

void Snake::clear(short bcolor,char btxt)
{
    for(short i = 0; i < length; i++)
    {
        grid.drawpnt(body[i],bcolor,btxt);
    }
}

bool Snake::nextPxlIs(short color,char txt,char facing_)
{
    if(facing == '0') return false;
    if(facing_ == '1') facing_ = getFacing();

    grph::Entity e;
    e.set(body[0]);

    if(e.nextPxlIs(grid,facing_,color,txt)) return true;

    return false;
}

