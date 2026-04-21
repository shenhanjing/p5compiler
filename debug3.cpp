void PrioritySelectFunc(uint<1> &OutValid, uint<0> &OutField, t_priority &OutPrio,
                        uint<1> InDefaultValid, uint<0> InDefaultField, t_priority InDefaultPrio, uint<8> Count,
                        uint<1> InValid[], uint<1> InCondFlag[], uint<0> InField[], t_priority InPrio[])
{
	if (Count <= 16)
	{
		_PA_PrioritySelectInt(OutValid, OutField, OutPrio,
									InDefaultValid, InDefaultField, InDefaultPrio, Count,
									InValid, InCondFlag, InField, InPrio);
	}
	else if (Count <= 31)
	{
		// uint<1>    Temp[1][sizeof(OutField)];
		uint<sizeof(OutField)> Temp[1];
		t_priority TempPrio[1];
		uint<1>    TempValid[1];
  }
}
