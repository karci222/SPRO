#include "systemc.h"

SC_MODULE(spravanie_counter){
	sc_in <sc_logic> UP;
	sc_in <sc_logic> ENABLE;
	sc_out <sc_uint<4> > OUTPUT;
	sc_out <sc_logic> COUT;
	sc_in <bool> CLK;

	void spravanie(){
		while (1){
			/*if (UP.read() == SC_LOGIC_0){
			wait(7, SC_NS);
			OUTPUT.write(0);
			}
			else {
			if (ENABLE.read() == SC_LOGIC_1){
			wait(3, SC_NS);
			OUTPUT.write(OUTPUT.read()+1);
			}
			}*/
			if (CLK.read() == SC_LOGIC_1){
				if (ENABLE.read() == SC_LOGIC_1){
					if (UP.read() == SC_LOGIC_1 && OUTPUT.read() < 15){
						wait(5, SC_NS);
						OUTPUT.write(OUTPUT.read() + 1);
						cout << "Value: " << OUTPUT.read() << endl;
					}
					if (UP.read() == SC_LOGIC_0 && OUTPUT.read() > 0){
						wait(5, SC_NS);
					    OUTPUT.write(OUTPUT.read() - 1);
						cout << "Value: " << OUTPUT.read() << endl;
					}
				}
				if (ENABLE.read() == SC_LOGIC_1){
					if (UP.read() == SC_LOGIC_1 && OUTPUT.read() == 15){
						COUT.write(SC_LOGIC_1);
						cout << "Value cout: " << COUT.read() << endl;
					}else if (UP.read() == SC_LOGIC_0 && OUTPUT.read() == 0){
						COUT.write(SC_LOGIC_1);
						cout << "Value cout: " << COUT.read() << endl;
					}
					else{
						COUT.write(SC_LOGIC_0);
						cout << "Value cout: " << COUT.read() << endl;
					}
				}
			}
			wait();
		}
	}
	SC_CTOR(spravanie_counter):UP("UP"),
		ENABLE("ENABLE"),
		OUTPUT("OUTPUT"),
		COUT("COUT"),
		CLK("CLK"){
		SC_THREAD(spravanie);
		sensitive << CLK.pos();
		
	}
};

SC_MODULE(dff)
{
    sc_in<bool> clk;
    sc_in<sc_logic> din;
    sc_out<sc_logic> dout;
    sc_out<sc_logic>notDout;
	sc_logic temp; //
    
    void p1(){
        while(TRUE){
            wait(5, SC_NS);
            dout.write(din.read());
            notDout.write(~din.read());
            wait();
        }
    }
    
    SC_CTOR(dff):clk("clk"), din("din"), dout("dout"), notDout("notDout"){
		dout.initialize(sc_logic_0);
		notDout.initialize(sc_logic_1);        
		SC_THREAD(p1);
        sensitive_pos << clk;
    }  
};

SC_MODULE(NAND2)
{
    sc_in<sc_logic> a;
    sc_in<sc_logic> b;
    sc_out<sc_logic> dout;
    
    void NAND()
    {
        dout.write(~(a.read() & b.read())); 
    }   
    
    SC_CTOR(NAND2):a("a"), b("b"), dout("dout")
    {
        SC_METHOD(NAND);   
        sensitive << a;
        sensitive << b;
    }
    
};

SC_MODULE(NAND3)
{
    sc_in<sc_logic> a;
    sc_in<sc_logic> b;
    sc_in<sc_logic> c;
    sc_out<sc_logic> dout;
    
    void NAND()
    {
       dout.write(~(a.read() & b.read() & c.read()));    
    }
    
    SC_CTOR(NAND3):a("a"), b("b"), c("c"), dout("dout")
    {
        SC_METHOD(NAND);
        sensitive << a;
        sensitive << b;
        sensitive << c;   
    }
};


SC_MODULE(NAND4)
{
    sc_in <sc_logic> a;
    sc_in <sc_logic> b;
    sc_in <sc_logic> c;
    sc_in <sc_logic> d;
    sc_out <sc_logic> dout;
    
    void NAND()
    {
        dout.write(~(a.read() & b.read() & c.read() & d.read()));
    }
    
    SC_CTOR(NAND4):a("a"), b("b"), c("c"), d("d"), dout("dout")
    {
        SC_METHOD(NAND);
        sensitive << a;
        sensitive << b;
        sensitive << c;
        sensitive << d;
    }   
};

SC_MODULE(NAND5)
{
    sc_in <sc_logic> a;
    sc_in <sc_logic> b;
    sc_in <sc_logic> c;
    sc_in <sc_logic> d;
    sc_in <sc_logic> e;
    sc_out <sc_logic> dout;
    
    void NAND()
    {
        dout.write(~(a.read() & b.read() & c.read() & d.read() & e.read()));
    }  
    
    SC_CTOR(NAND5):a("a"), b("b"), c("c"), d("d"), e("e"), dout("dout")
    {
        SC_METHOD(NAND);
        sensitive << a;
        sensitive << b;
        sensitive << c;
        sensitive << d;
        sensitive << e;   
    }
};

SC_MODULE(NAND6)
{
    sc_in <sc_logic> a;
    sc_in <sc_logic> b;
    sc_in <sc_logic> c;
    sc_in <sc_logic> d;
    sc_in <sc_logic> e;
    sc_in <sc_logic> f;
    sc_out <sc_logic> dout;
    
    void NAND()
    {
        dout.write(~(a.read() & b.read() & c.read() & d.read() & e.read() & f.read()));
    }  
    
    SC_CTOR(NAND6):a("a"), b("b"), c("c"), d("d"), e("e"), f("f"), dout("dout")
    {
        SC_METHOD(NAND);
        sensitive << a;
        sensitive << b;
        sensitive << c;
        sensitive << d;
        sensitive << e;
        sensitive << f;   
    }
};

SC_MODULE(NAND7)
{
    sc_in <sc_logic> a;
    sc_in <sc_logic> b;
    sc_in <sc_logic> c;
    sc_in <sc_logic> d;
    sc_in <sc_logic> e;
    sc_in <sc_logic> f;
    sc_in <sc_logic> g;
    sc_out <sc_logic> dout;
    
    void NAND()
    {
        dout.write(~(a.read() & b.read() & c.read() & d.read() & e.read() & f.read() & g.read()));    
    }   
    
    SC_CTOR(NAND7):a("a"), b("b"), c("c"), d("d"), e("e"), f("f"), g("g"), dout("dout")
    {
        SC_METHOD(NAND);
        sensitive << a; 
        sensitive << b;
        sensitive << c;
        sensitive << d;
        sensitive << e;
        sensitive << f; 
        sensitive << g;  
    }
};

SC_MODULE(invertor)
{
	sc_in <sc_logic> din;
	sc_out<sc_logic> dout;
	
	void negation()
	{
		dout.write(~(din.read()));
	}
	
	SC_CTOR(invertor):din("din"), dout("dout")
	{
		SC_METHOD(negation);
		sensitive << din;
	}
};

SC_MODULE(struktura_counter)
{
    sc_in <sc_logic> up;
	sc_in <sc_logic> enable;
	sc_out <sc_logic> output1;
	sc_out <sc_logic> output2;
	sc_out <sc_logic> output3;
	sc_out <sc_logic> output4;
	sc_out <sc_logic> cout;
	sc_in <bool> clk;
    
	/*
    sc_bv<22> s;
    sc_bv<4> din;
    sc_bv<4> z;
    sc_bv<4> notz;
	*/
	
	sc_signal <sc_logic> S1;
	sc_signal <sc_logic> S2;
	sc_signal <sc_logic> S3;
	sc_signal <sc_logic> S4;
	sc_signal <sc_logic> S5;
	sc_signal <sc_logic> S6;
	sc_signal <sc_logic> S7;
	sc_signal <sc_logic> S8;
	sc_signal <sc_logic> S9;
	sc_signal <sc_logic> S10;
	sc_signal <sc_logic> S11;
	sc_signal <sc_logic> S12;
	sc_signal <sc_logic> S13;
	sc_signal <sc_logic> S14;
	sc_signal <sc_logic> S15;
	sc_signal <sc_logic> S16;
	sc_signal <sc_logic> S17;
	sc_signal <sc_logic> S18;
	sc_signal <sc_logic> S19;
	sc_signal <sc_logic> S20;
	sc_signal <sc_logic> S21;
	sc_signal <sc_logic> S0;
	
	sc_signal <sc_logic> cout_pom;
	sc_signal <sc_logic> not_cout;
	
	sc_signal <sc_logic> d2_1;
	sc_signal <sc_logic> d2_2;
	sc_signal <sc_logic> d2_3;
	sc_signal <sc_logic> d2_4;
	
	sc_signal <sc_logic> Z0;
	sc_signal <sc_logic> Z1;
	sc_signal <sc_logic> Z2;
	sc_signal <sc_logic> Z3;
	
	sc_signal <sc_logic> notZ0;
	sc_signal <sc_logic> notZ1;
	sc_signal <sc_logic> notZ2;
	sc_signal <sc_logic> notZ3;
	
	
	sc_signal <sc_logic> notenable;
	sc_signal <sc_logic> notup;
    
    NAND5 *s0;
    NAND2 *s1;
    NAND2 *s2;
    NAND2 *s3;
    NAND2 *s4;
    NAND2 *s5;
    NAND6 *z1;
    dff   *d1ff;
    
    NAND6 *s6;
    NAND5 *s7; 
    NAND6 *s8;
    NAND3 *s9;
    NAND3 *s10;
    NAND3 *s11;
    NAND2 *s12;
    NAND7 *z2;
    dff   *d2ff;
    
    //pouzite s6
    NAND5 *s13;
    //pouzijem s8
    NAND4 *s14;
    NAND3 *s15;
    NAND3 *s16;
    NAND2 *s17;
    NAND7 *z3; 
    dff   *d3ff;
    
    //pouzijem s6
    //pouzijem s13
    //pouzijem s8
    NAND3 *s18;
    NAND3 *s19;
    NAND2 *s20;
    NAND6 *z4;
    dff   *d4ff;
    
    NAND6 *s21;
    //pouzijem s8
    NAND2 *cout_log;
    
    //
    invertor *inv1;
    invertor *inv2;
    invertor *inv3;
    invertor *inv4;
    
    dff *dcoutff;
    
    void count()
    {
           
    }
	
	SC_CTOR(struktura_counter):clk("clk"), up("up"), enable("enable"), cout("cout"), output1("output1"),
	output2("output2"), output3("output3"), output4("output4")
	{
	    
	    Z0 = sc_logic_0;
	    Z1 = sc_logic_0;
	    Z2 = sc_logic_0;
	    Z3 = sc_logic_0;
		
		notZ0 = sc_logic_1;
		notZ1 = sc_logic_1;
		notZ2 = sc_logic_1;
		notZ3 = sc_logic_1;
		
	    
	    
	    inv1 = new invertor("inv1");
	    inv2 = new invertor("inv2");
	    (*inv1)(up, notup);
	    (*inv2)(enable, notenable);
	    
	       
	    s0 = new NAND5("s0");
		(*s0)(Z2, Z1, Z0, up, enable, S0);
		s1 = new NAND2("s1");
		(*s1)(notZ3, notenable, S1);
		s2 = new NAND2("s2");
		(*s2)(Z3, up, S2);
        s3 = new NAND2("s3");
        (*s3)(Z3, Z0, S3);
        s4 = new NAND2("s4");
        (*s4)(Z3, Z2, S4);
        s5 = new NAND2("s5");
        (*s5)(Z3, Z1, S5);
        z1 = new NAND6("z1");
        (*z1)(S0, S1, S2, S3, S4, S5, d2_1);
        d1ff = new dff("d1ff");
        (*d1ff)(clk, d2_1, Z3, notZ3);
        
        s6 = new NAND6("s6");
        (*s6)(Z3, notZ2, notZ1, notZ0, notup, enable, S6);
        s7 = new NAND5("s7"); 
        (*s7)(notZ2, Z1, Z0, up, enable, S7);
        s8 = new NAND6("s8");
        (*s8)(Z0, Z1, Z2, Z3, up, enable, S8);
        s9 = new NAND3("s9");
        (*s9)(Z2, notZ0, up, S9);
        s10 = new NAND3("s10");
        (*s10)(Z2, notZ1, Z0, S10);
        s11 = new NAND3("s11");
        (*s11)(Z2, Z1, notup, S11);
        s12 = new NAND2("s12");
        (*s12)(Z2, notenable, S12);
        z2 = new NAND7("z2");
        (*z2)(S6, S7, S8, S9, S10, S11, S12, d2_2);
        d2ff = new dff("d2ff");
        (*d2ff)(clk, d2_2, Z2, notZ2);
        
		//pouzite s6
        s13 = new NAND5("s13");
        (*s13)(Z2, notZ1, notZ0, notup, enable, S13);
		//pouzijem s8
        s14 = new NAND4("s14");
        (*s14)(notZ1, Z0, up, enable, S14);
        s15 = new NAND3("s15");
        (*s15)(Z1, notZ0, up, S15);
        s16 = new NAND3("s16");
        (*s16)(Z1, Z0, notup, S16);
        s17 = new NAND2("s17");
        (*s17)(Z1, notenable, S17);
        z3 = new NAND7("z3");
        (*z3)(S6, S13, S8, S14, S15, S16, S17, d2_3);
        d3ff = new dff("d3ff");
        (*d3ff)(clk, d2_3,  Z1, notZ1);
        
		//pouzijem s6
		//pouzijem s13
		//pouzijem s8
        s18 = new NAND3("s18");
        (*s18)(notZ0, up, enable, S18);
        s19 = new NAND3("s19");
        (*s19)(Z1, notZ0, enable, S19);
        s20 = new NAND2("s20");
        (*s20)(Z0, notenable, S20);
        z4 = new NAND6("z4");
        (*z4)(S6, S13, S8, S18, S19, S20, d2_4);
        d4ff = new dff("d4ff");
        (*d4ff)(clk, d2_4, Z0, notZ0);
        
        s21 = new NAND6("s21");
        (*s21)(notZ0, notZ1, notZ2, notZ3, notup, enable, S21);
		 //pouzijem s8
        cout_log = new NAND2("cout_log");
        (*cout_log)(S8, S21, cout_pom);
        
        dcoutff = new dff("dcoutff");
        (*dcoutff)(clk, cout_pom, cout, not_cout);
        
        
	}
};


SC_MODULE(testbench)
{
    sc_clock clk_sig;
    sc_signal<sc_logic> up;
    sc_signal<sc_logic> enable;
    sc_signal<sc_logic> cout;
    sc_signal<sc_uint<4> > output;
    sc_lv<4> output2;
    dff *dff0; 
    spravanie_counter *behaviour;
    NAND3 *nand;
    
    sc_signal<sc_logic> clk_reference;
    
    void test(){
       
    }
    
    SC_CTOR(testbench):clk_sig("clk_sig", 10, SC_NS){
        /*dff0 = new dff("dff0");
        dff0->clk(clk_sig);
        dff0->din(enable);
        dff0->dout(up);
        dff0->notDout(cout);*/
        
        /*
        up = sc_logic_0;
        enable = sc_logic_1;
        
        behaviour = new spravanie_counter("behaviour");
        behaviour->CLK(clk_sig);
        behaviour->UP(up);
        behaviour->ENABLE(enable);
        behaviour->COUT(cout);
        behaviour->OUTPUT(output);
        */
        
        struktura_counter *structure = new struktura_counter("structure");
        structure->clk(clk_sig);
        structure->up(up);
        structure->enable(enable);
        structure->cout(cout);
       /* structure->output1(output2[3]);
        structure->output2(output2[2]);
        structure->output3(output2[1]);
        structure->output4(output2[0]);*/
    }
};



//SC_MODULE_EXPORT(testbench);
SC_MODULE_EXPORT(testbench);
SC_MODULE_EXPORT(NAND2);