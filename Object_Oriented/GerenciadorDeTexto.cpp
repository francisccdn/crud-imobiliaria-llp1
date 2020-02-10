#include "GerenciadorDeTexto.h"
#include <iostream>

std::string GerenciadorDeTexto::strToLower(std::string str){
    for(int i = 0; i < str.length(); i++){
        str[i] = tolower(str[i]);
    }
    return str;
}

//A fazer
std::string GerenciadorDeTexto::removeAcento(std::string str){
    std::string comAcentos = "ÄÅÁÂÀÃäáâàãÉÊËÈéêëèÍÎÏÌíîïìÖÓÔÒÕöóôòõÜÚÛüúûùÇç";
    std::string semAcentos = "AAAAAAaaaaaEEEEeeeeIIIIiiiiOOOOOoooooUUUuuuuCc";
    
    for (int i = 0; i < comAcentos.length(); i++)
    {
       // str = str.replace(comAcentos[i].ToString(), semAcentos[i].ToString());
    }
    return str;
}