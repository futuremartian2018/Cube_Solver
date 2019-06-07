

class Obrot {
    private: 
    static int par ;
    static const int a = 1000;
    static const int b = 385;
    static const int kom = 100;
    public:
 static void obrot_180(){
            /*   hMot1.resetEncoderCnt();
                hMot1.rotAbs(1080 , 500, true, INFINITE);
                sys.delay(650);
                 hMot1.resetEncoderCnt();
                hMot1.rotAbs(100, 500, true, INFINITE);
                sys.delay(650);
                hMot1.resetEncoderCnt();
                 hMot1.rotAbs(-100, 500, true, INFINITE);
                sys.delay(650);*/
                if(par%2 == 0){
                 hMot1.resetEncoderCnt();
                 hMot1.rotAbs(540, a, true, INFINITE);
                sys.delay(650);
                hMot1.resetEncoderCnt();
                hMot1.rotAbs(kom, a, true, INFINITE);
                sys.delay(650);
                hMot1.resetEncoderCnt();
                 hMot1.rotAbs(-kom, a, true, INFINITE);
                sys.delay(650);
                 hMot1.resetEncoderCnt();
                 hMot1.rotAbs(540, a, true, INFINITE);
                sys.delay(650);
                hMot1.resetEncoderCnt();
                hMot1.rotAbs(kom, a, true, INFINITE);
                sys.delay(650);
                hMot1.resetEncoderCnt();
                 hMot1.rotAbs(-kom, a, true, INFINITE);
                sys.delay(650);}
                else {
                 hMot1.resetEncoderCnt();
                 hMot1.rotAbs(-540, a, true, INFINITE);
                sys.delay(650);
                hMot1.resetEncoderCnt();
                hMot1.rotAbs(-kom, a, true, INFINITE);
                sys.delay(650);
                hMot1.resetEncoderCnt();
                 hMot1.rotAbs(kom, a, true, INFINITE);
                sys.delay(650);
                 hMot1.resetEncoderCnt();
                 hMot1.rotAbs(-540, a, true, INFINITE);
                sys.delay(650);
                hMot1.resetEncoderCnt();
                hMot1.rotAbs(-kom, a, true, INFINITE);
                sys.delay(650);
                hMot1.resetEncoderCnt();
                 hMot1.rotAbs(kom, a, true, INFINITE);
                sys.delay(650);}
                
                par = par + 1;
                Serial.printf("%d\n", par);

 }
static void obrot_90L(){
                hMot1.resetEncoderCnt();
                 hMot1.rotAbs(540, a, true, INFINITE);
                sys.delay(650);
                hMot1.resetEncoderCnt();
                hMot1.rotAbs(kom, a, true, INFINITE);
                sys.delay(650);
                hMot1.resetEncoderCnt();
                 hMot1.rotAbs(-kom, a, true, INFINITE);
                sys.delay(650);

}

 static void obrot_90P(){
                hMot1.resetEncoderCnt();
                hMot1.rotAbs(-540, a, true, INFINITE);
                sys.delay(650);
                hMot1.resetEncoderCnt();
                hMot1.rotAbs(-kom, a, true, INFINITE);
                sys.delay(650);
                hMot1.resetEncoderCnt();
                hMot1.rotAbs(kom, a, true, INFINITE);
                sys.delay(650);
}

static void uciekaj(){
               hMot2.resetEncoderCnt();
                hMot2.rotAbs(-250, b, true, INFINITE);
                sys.delay(500);
}

static void zlap(){
                hMot2.resetEncoderCnt();
                hMot2.rotAbs(250, b, true, INFINITE);
                sys.delay(500);
}
static void przerzuc(){
                hMot2.resetEncoderCnt();
                hMot2.rotAbs(185, 1000, true, INFINITE);
                sys.delay(500);
                hMot2.resetEncoderCnt();
                hMot2.rotAbs(-185, 1000, true, INFINITE);
                sys.delay(500);
               hMot2.resetEncoderCnt();
               hMot2.rotAbs(-45, 400, true, INFINITE);
                sys.delay(500);
                hMot2.resetEncoderCnt();
                hMot2.rotAbs(45, 520, true, INFINITE);
                sys.delay(500);
}

};