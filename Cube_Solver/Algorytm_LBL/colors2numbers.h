   #include "Tile.h"
   #include <stdio.h>
    class Colors2Numbers {
        private:
           char colors[6][9];
            
            Tile *edges[3][13];
            Tile *corners[8][3];

    static  const int TILESONONEWALL = 9;
    static const int WALLS = 6;


    public:
    static int numbers[6][9];
         Colors2Numbers( char c[6][9]) {
       /* colors = new char[WALLS][TILESONONEWALL];
        numbers = new int[WALLS][TILESONONEWALL];
        corners = new Tile[8][3];
        Tile edges = new Tile[3][13];*/

        this->setColors(c);
        this->changeColorsPositions();

        edges[0][0] = new Tile(0, 0, 'z');
        edges[0][1] = new Tile(0, 7, colors[0][7]);
        edges[0][2] = new Tile(1, 1, colors[1][1]);
        edges[0][3] = new Tile(0, 0, 'x');
        edges[0][4] = new Tile(1, 7, colors[1][7]);
        edges[0][5] = new Tile(5, 1, colors[5][1]);
        edges[0][6] = new Tile(0, 0, 'x');
        edges[0][7] = new Tile(5, 7, colors[5][7]);
        edges[0][8] = new Tile(3, 7, colors[3][7]);
        edges[0][9] = new Tile(0, 0, 'x');
        edges[0][10] = new Tile(3, 1, colors[3][1]);
        edges[0][11] = new Tile(0, 1, colors[0][1]);
        edges[0][12] = new Tile(0, 0, 'x');

        edges[1][0] = new Tile(0, 0, 'z');
        edges[1][1] = new Tile(0, 5, colors[0][5]);
        edges[1][2] = new Tile(2, 1, colors[2][1]);
        edges[1][3] = new Tile(0, 0, 'x');
        edges[1][4] = new Tile(2, 7, colors[2][7]);
        edges[1][5] = new Tile(5, 5, colors[5][5]);
        edges[1][6] = new Tile(0, 0, 'x');
        edges[1][7] = new Tile(5, 3, colors[5][3]);
        edges[1][8] = new Tile(4, 7, colors[4][7]);
        edges[1][9] = new Tile(0, 0, 'x');
        edges[1][10] = new Tile(4, 1, colors[4][1]);
        edges[1][11] = new Tile(0, 3, colors[0][3]);
        edges[1][12] = new Tile(0, 0, 'x');

        edges[2][0] = new Tile(0, 0, 'z');
        edges[2][1] = new Tile(1, 5, colors[1][5]);
        edges[2][2] = new Tile(2, 3, colors[2][3]);
        edges[2][3] = new Tile(0, 0, 'x');
        edges[2][4] = new Tile(2, 5, colors[2][5]);
        edges[2][5] = new Tile(3, 3, colors[3][3]);
        edges[2][6] = new Tile(0, 0, 'x');
        edges[2][7] = new Tile(3, 5, colors[3][5]);
        edges[2][8] = new Tile(4, 3, colors[4][3]);
        edges[2][9] = new Tile(0, 0, 'x');
        edges[2][10] = new Tile(4, 5, colors[4][5]);
        edges[2][11] = new Tile(1, 3, colors[1][3]);
        edges[2][12] = new Tile(0, 0, 'x');

        corners[0][0] = new Tile(0, 0, colors[0][0]);
        corners[0][1] = new Tile(3, 2, colors[3][2]);
        corners[0][2] = new Tile(4, 0, colors[4][0]);

        corners[1][0] = new Tile(0, 2, colors[0][2]);
        corners[1][1] = new Tile(3, 0, colors[3][0]);
        corners[1][2] = new Tile(2, 2, colors[2][2]);

        corners[2][0] = new Tile(0, 6, colors[0][6]);
        corners[2][1] = new Tile(1, 0, colors[1][0]);
        corners[2][2] = new Tile(4, 2, colors[4][2]);

        corners[3][0] = new Tile(0, 8, colors[0][8]);
        corners[3][1] = new Tile(1, 2, colors[1][2]);
        corners[3][2] = new Tile(2, 0, colors[2][0]);

        corners[4][0] = new Tile(5, 0, colors[5][0]);
        corners[4][1] = new Tile(1, 6, colors[1][6]);
        corners[4][2] = new Tile(4, 8, colors[4][8]);

        corners[5][0] = new Tile(5, 2, colors[5][2]);
        corners[5][1] = new Tile(1, 8, colors[1][8]);
        corners[5][2] = new Tile(2, 6, colors[2][6]);

        corners[6][0] = new Tile(5, 6, colors[5][6]);
        corners[6][1] = new Tile(3, 8, colors[3][8]);
        corners[6][2] = new Tile(4, 6, colors[4][6]);

        corners[7][0] = new Tile(5, 8, colors[5][8]);
        corners[7][1] = new Tile(3, 6, colors[3][6]);
        corners[7][2] = new Tile(2, 8, colors[2][8]);


        for (int i = 0; i < WALLS; i++) {
            for (int j = 0; j < TILESONONEWALL; j++) {
                numbers[i][j] = 0;
            }
        }
    }

     void convertColorsToNumbers() {
        this->convertCenters();
        this->convertEdges();
        this->convertCorners();
        
    }


     void convertCenters() {
        for (int i = 0; i < WALLS; i++) {
            if (colors[i][4] == 'w') { numbers[i][4] =  5; }
            if (colors[i][4] == 'r') { numbers[i][4] = 14; }
            if (colors[i][4] == 'b') { numbers[i][4] = 23; }
            if (colors[i][4] == 'o') { numbers[i][4] = 32; }
            if (colors[i][4] == 'g') { numbers[i][4] = 41; }
            if (colors[i][4] == 'y') { numbers[i][4] = 50; }
        }
    }

     void convertCorners(){
        for (int  i = 0;i < 8;i++){
            for (int j = 0; j < 3;j++){
                if (corners[i][j] ->getColor() == 'w'){
                    for (int k = 0;k < 3;k++){
                        if (corners[i][k] -> getColor() == 'r'){
                            for (int m = 0;m < 3;m++){
                                if (corners[i][m] -> getColor() == 'g'){
                                    numbers[corners[i][j] -> getW()][corners[i][j] -> getT()] = 7;
                                    numbers[corners[i][k] -> getW()][corners[i][k] -> getT()] = 10;
                                    numbers[corners[i][m] -> getW()][corners[i][m] -> getT()] = 39;
                                }else if (corners[i][m] -> getColor() == 'b'){
                                    numbers[corners[i][j] -> getW()][corners[i][j] -> getT()] = 9;
                                    numbers[corners[i][k] -> getW()][corners[i][k] -> getT()] = 12;
                                    numbers[corners[i][m] -> getW()][corners[i][m] -> getT()] = 19;
                                }
                            }
                        }else if (corners[i][k] -> getColor() == 'o'){
                            for (int m = 0;m < 3;m++){
                                if (corners[i][m] -> getColor() == 'g'){
                                    numbers[corners[i][j] -> getW()][corners[i][j] -> getT()] = 1;
                                    numbers[corners[i][k] -> getW()][corners[i][k] -> getT()] = 30;
                                    numbers[corners[i][m] -> getW()][corners[i][m] -> getT()] = 37;
                                }else if (corners[i][m] -> getColor() == 'b'){
                                    numbers[corners[i][j] -> getW()][corners[i][j] -> getT()] = 3;
                                    numbers[corners[i][k] -> getW()][corners[i][k] -> getT()] = 28;
                                    numbers[corners[i][m] -> getW()][corners[i][m] -> getT()] = 21;
                                }
                            }
                        }
                    }
                }else if(corners[i][j] -> getColor() == 'y'){
                    for (int k = 0;k < 3;k++){
                        if (corners[i][k] -> getColor() == 'r'){
                            for (int m = 0;m < 3;m++){
                                if (corners[i][m] -> getColor() == 'g'){
                                    numbers[corners[i][j] -> getW()][corners[i][j] -> getT()] = 46;
                                    numbers[corners[i][k] -> getW()][corners[i][k] -> getT()] = 16;
                                    numbers[corners[i][m] -> getW()][corners[i][m] -> getT()] = 45;
                                }else if (corners[i][m] -> getColor() == 'b'){
                                    numbers[corners[i][j] -> getW()][corners[i][j] -> getT()] = 48;
                                    numbers[corners[i][k] -> getW()][corners[i][k] -> getT()] = 18;
                                    numbers[corners[i][m] -> getW()][corners[i][m] -> getT()] = 25;
                                }
                            }
                        }else if (corners[i][k] -> getColor() == 'o'){
                            for (int m = 0;m < 3;m++){
                                if (corners[i][m] -> getColor() == 'g'){
                                    numbers[corners[i][j] -> getW()][corners[i][j] -> getT()] = 52;
                                    numbers[corners[i][k] -> getW()][corners[i][k] -> getT()] = 36;
                                    numbers[corners[i][m] -> getW()][corners[i][m] -> getT()] = 43;
                                }else if (corners[i][m] -> getColor() == 'b'){
                                    numbers[corners[i][j] -> getW()][corners[i][j] -> getT()] = 54;
                                    numbers[corners[i][k] -> getW()][corners[i][k] -> getT()] = 34;
                                    numbers[corners[i][m] -> getW()][corners[i][m] -> getT()] = 27;
                                }
                            }
                        }
                    }
                }
            }
        }
    }


     void convertEdges() {
        for (int k = 0;k < 3;k++)
        {
            for (int i = 0; i < 13 ; i++) {

                int a, b;

                if (i == 0) {
                 a = i + 1;
                } else {
                    a = i - 1;
                }

                if (i == 12) {
                    b = i - 1;
                } else {
                    b = i + 1;
                }

                if (edges[k][i] -> getColor() == 'w') {
                    if (edges[k][a] -> getColor() == 'o') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 2;
                        numbers[edges[k][a] -> getW()][edges[k][a] -> getT()] = 29;
                    } else if (edges[k][b] -> getColor() == 'o') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 2;
                        numbers[edges[k][b] -> getW()][edges[k][b] -> getT()] = 29;
                    } else if (edges[k][a] -> getColor() == 'g') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 4;
                        numbers[edges[k][a] -> getW()][edges[k][a] -> getT()] = 38;
                    } else if (edges[k][b] -> getColor() == 'g') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 4;
                        numbers[edges[k][b] -> getW()][edges[k][b] -> getT()] = 38;
                    } else if (edges[k][a] -> getColor() == 'b') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 6;
                        numbers[edges[k][a] -> getW()][edges[k][a] -> getT()] = 20;
                    } else if (edges[k][b] -> getColor() == 'b') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 6;
                        numbers[edges[k][b] -> getW()][edges[k][b] -> getT()] = 20;
                    } else if (edges[k][a] -> getColor() == 'r') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 8;
                        numbers[edges[k][a] -> getW()][edges[k][a] -> getT()] = 11;
                    } else if (edges[k][b] -> getColor() == 'r') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 8;
                        numbers[edges[k][b] -> getW()][edges[k][b] -> getT()] = 11;
                    }
                } else if (edges[k][i] -> getColor() == 'y') {
                    if (edges[k][a] -> getColor() == 'o') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 53;
                        numbers[edges[k][a] -> getW()][edges[k][a] -> getT()] = 35;
                    } else if (edges[k][b] -> getColor() == 'o') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 53;
                        numbers[edges[k][b] -> getW()][edges[k][b] -> getT()] = 35;
                    } else if (edges[k][a] -> getColor() == 'g') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 49;
                        numbers[edges[k][a] -> getW()][edges[k][a] -> getT()] = 44;
                    } else if (edges[k][b] -> getColor() == 'g') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 49;
                        numbers[edges[k][b] -> getW()][edges[k][b] -> getT()] = 44;
                    } else if (edges[k][a] -> getColor() == 'b') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 51;
                        numbers[edges[k][a] -> getW()][edges[k][a] -> getT()] = 26;
                    } else if (edges[k][b] -> getColor() == 'b') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 51;
                        numbers[edges[k][b] -> getW()][edges[k][b] -> getT()] = 26;
                    } else if (edges[k][a] -> getColor() == 'r') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 47;
                        numbers[edges[k][a] -> getW()][edges[k][a] -> getT()] = 17;
                    } else if (edges[k][b] -> getColor() == 'r') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 47;
                        numbers[edges[k][b] -> getW()][edges[k][b] -> getT()] = 17;
                    }
                } else if (edges[k][i] -> getColor() == 'r') {
                    if (edges[k][a] -> getColor() == 'g') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 13;
                        numbers[edges[k][a] -> getW()][edges[k][a] -> getT()] = 42;
                    } else if (edges[k][b] -> getColor() == 'g') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 13;
                        numbers[edges[k][b] -> getW()][edges[k][b] -> getT()] = 42;
                    } else if (edges[k][a] -> getColor() == 'b') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 15;
                        numbers[edges[k][a] -> getW()][edges[k][a] -> getT()] = 22;
                    } else if (edges[k][b] -> getColor() == 'b') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 15;
                        numbers[edges[k][b] -> getW()][edges[k][b] -> getT()] = 22;
                    }
                } else if (edges[k][i] -> getColor() == 'o') {
                    if (edges[k][a] -> getColor() == 'b') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 31;
                        numbers[edges[k][a] -> getW()][edges[k][a] -> getT()] = 24;
                    } else if (edges[k][b] -> getColor() == 'b') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 31;
                        numbers[edges[k][b] -> getW()][edges[k][b] -> getT()] = 24;
                    } else if (edges[k][a] -> getColor() == 'g') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 33;
                        numbers[edges[k][a] -> getW()][edges[k][a] -> getT()] = 40;
                    } else if (edges[k][b] -> getColor() == 'g') {
                        numbers[edges[k][i] -> getW()][edges[k][i] -> getT()] = 33;
                        numbers[edges[k][b] -> getW()][edges[k][b] -> getT()] = 40;
                    }
                }
            }
        }
    }




    void setColors(  char colorss[6][9]){

        for (int i = 0; i < WALLS; i++) {
            for (int j = 0; j < TILESONONEWALL; j++) {
                colors[i][j] = colorss[i][j];
            }
        }
    }

    void showNumbers() {

        for (int i = 0; i < WALLS; i++) {
            for (int j = 0; j < TILESONONEWALL; j++) {
               // Serial.printf("%6d", numbers[i][j]);
            }
           // Serial.printf("\n");
        }
    }

     void showColors() {

        for (int i = 0; i < WALLS; i++) {
            for (int j = 0; j < TILESONONEWALL; j++) {
              //  Serial.printf("%6c", colors[i][j]);
            }
           // Serial.printf("\n");
        }
    }

    void changeColorsPositions() {

        char c[6][9];
        char d[6][9];


        for (int i = 0; i < WALLS; i++) {
            for (int j = 0; j < TILESONONEWALL; j++) {
                c[i][j] = colors[i][j];
            }
        }
        for (int i = 0; i < WALLS; i++) {

            if (colors[i][4] == 'w') {
                for (int k = 0; k < WALLS; k++) {
                    for (int j = 0; j < TILESONONEWALL; j++) {
                        d[0][j] = c[i][j];
                    }
                }
            }
            if (colors[i][4] == 'r') {
                for (int k = 0; k < WALLS; k++) {
                    for (int j = 0; j < TILESONONEWALL; j++) {
                        d[1][j] = c[i][j];
                    }
                }
            }
            if (colors[i][4] == 'b') {
                for (int k = 0; k < WALLS; k++) {
                    for (int j = 0; j < TILESONONEWALL; j++) {
                        d[2][j] = c[i][j];
                    }
                }
            }
            if (colors[i][4] == 'o') {
                for (int k = 0; k < WALLS; k++) {
                    for (int j = 0; j < TILESONONEWALL; j++) {
                        d[3][j] = c[i][j];
                    }
                }
            }
            if (colors[i][4] == 'g') {
                for (int k = 0; k < WALLS; k++) {
                    for (int j = 0; j < TILESONONEWALL; j++) {
                        d[4][j] = c[i][j];
                    }
                }
            }
            if (colors[i][4] == 'y') {
                for (int k = 0; k < WALLS; k++) {
                    for (int j = 0; j < TILESONONEWALL; j++) {
                        d[5][j] = c[i][j];
                    }
                }
            }
        }
        for (int i = 0; i < WALLS; i++) {
            for (int j = 0; j < TILESONONEWALL; j++) {
                colors[i][j] = d[i][j];
            }
        }
    }
};


