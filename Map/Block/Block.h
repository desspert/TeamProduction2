#pragma once
#include "../../Classbase.h"
#include "../../Share/Share.h"

//shareに追加する分



//



class Block : public Classbase
{
private:

	Maptype map_type;

public:

	Block();

	Maptype Getmaptype();
	void Setmaptype(int);

	void Setup();
	void Update();
	void Draw();


};