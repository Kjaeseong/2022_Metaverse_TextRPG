while (_hp + _spd + _str + _dex + _int < 40)
{
	int rand = dice(1, 5);
	switch (rand)
	{
	case 1:
		_hp + 1;
		cout << "1 Áõ°¡";
		break;
	case 2:
		_str + 1;
		break;
	case 3:
		_dex + 1;
		break;
	case 4:
		_int + 1;
		break;
	case 5:
		_spd + 1;
		break;
	}
}
dice(1, 5)

