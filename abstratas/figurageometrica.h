#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

class figuraGeometrica{
public:
    figuraGeometrica();
    virtual figuraGeometrica~();//necessário para chamar os destrutores das subclasses;
    //Essa classe é abstrata, pois possui uma função virtual pura
    virtual void draw()=0;//executa o metodo que esta implementado na subclasse, é obrigatório existir pelo menos um método virtual puro para uma classe abstrata
};

#endif // FIGURAGEOMETRICA_H
