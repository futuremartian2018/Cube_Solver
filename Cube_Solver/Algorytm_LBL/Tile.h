
 class Tile {
    private:
     int w; //wspolrzedna kafelka opisujaca numer sciany
     int t; //wpsolrzedna kafelka opisujaca jego numer na danej scianie
     char color; //kolor kafelka




    public: 
    Tile(int ww, int tt, char colorc){
        w = ww;
        t = tt;
        color = colorc;
    }

    Tile(){
        w = 0;
        t = 0;
        color = 'x';
    }

     int getW() {
        return w;
    }

     void setW(int ww) {
        w = ww;
    }

     int getT() {
        return t;
    }

     void setT(int tt) {
        t = tt;
    }

     char getColor() {
        return color;
    }

     void setColor(char colorc) {
        color = colorc;
    }
};
