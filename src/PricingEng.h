#ifndef PRICINGENG_EX32_H
#define PRICINGENG_EX32_H

class Option;
class Arguments;

class PricingEng
{
    public:
        PricingEng(Option*);
        PricingEng(Arguments&);
        virtual double price(){return 0.0;}
        virtual double price(Arguments&){return 0.0;}
    protected:
        Option* opt_;
};


#endif
