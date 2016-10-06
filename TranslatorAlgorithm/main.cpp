#include <vector>
#include <iostream>

using namespace std;

void PartialDecoding (vector<int>& tmp_vector_reference, int converting_sum)
{
	
	/*
	1 2 4 8
	
	3 5 9 6 10 12
	
	7 11 14
	
	15
	
	1:1
	2:2
	4:3
	8:4
	
	3:1&2
	5:1&3
	9:1&4
	6:2&3
	10:2&4
	12:3&4
	
	7:1&2&3
	11:1&2&4
	13:1&3&4
	14:2&3&4
	
	15:1&2&3&4
	*/
	
	if (converting_sum == 1)
	{
		tmp_vector_reference.push_back(1);
	}
	else if (converting_sum == 2)
	{
		tmp_vector_reference.push_back(2);
	}
	else if (converting_sum == 4)
	{
		tmp_vector_reference.push_back(3);
	}
	else if (converting_sum == 8)
	{
		tmp_vector_reference.push_back(4);
	}
	else if (converting_sum == 3)
	{
		tmp_vector_reference.push_back(1);
		tmp_vector_reference.push_back(2);
	}
	else if (converting_sum == 5)
	{
		tmp_vector_reference.push_back(1);
		tmp_vector_reference.push_back(3);
	}
	else if (converting_sum == 9)
	{
		tmp_vector_reference.push_back(1);
		tmp_vector_reference.push_back(4);
	}
	else if (converting_sum == 6)
	{
		tmp_vector_reference.push_back(2);
		tmp_vector_reference.push_back(3);
	}
	else if (converting_sum == 10)
	{
		tmp_vector_reference.push_back(2);
		tmp_vector_reference.push_back(4);
	}
	else if (converting_sum == 12)
	{
		tmp_vector_reference.push_back(3);
		tmp_vector_reference.push_back(4);
	}
	else if (converting_sum == 7)
	{
		tmp_vector_reference.push_back(1);
		tmp_vector_reference.push_back(2);
		tmp_vector_reference.push_back(3);
	}
	else if (converting_sum == 11)
	{
		tmp_vector_reference.push_back(1);
		tmp_vector_reference.push_back(2);
		tmp_vector_reference.push_back(4);
	}
	else if (converting_sum == 13)
	{
		tmp_vector_reference.push_back(1);
		tmp_vector_reference.push_back(3);
		tmp_vector_reference.push_back(4);
	}
	else if (converting_sum == 14)
	{
		tmp_vector_reference.push_back(2);
		tmp_vector_reference.push_back(3);
		tmp_vector_reference.push_back(4);
	}
	else if (converting_sum == 15)
	{
		tmp_vector_reference.push_back(1);
		tmp_vector_reference.push_back(2);
		tmp_vector_reference.push_back(3);
		tmp_vector_reference.push_back(4);
	}
}

void DecodeSum ( vector<int>& decode_array, unsigned int converting_sum, int table_pointer )
{
	vector<int> tmp_vector;
	vector<int>& tmp_vector_reference = tmp_vector;
	
	int i = 0;
	
	if (table_pointer == 0)
	{
		PartialDecoding(tmp_vector_reference, converting_sum);
		
		for (i = 0; i < tmp_vector_reference.size(); i++)
		{
			decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);
			
			//cout << "table_pointer 0 " << tmp_vector_reference[i] << endl;
			
		}
		
	}
	else if (table_pointer == 1)
	{
		PartialDecoding(tmp_vector_reference, converting_sum);
		
		for (i = 0; i < tmp_vector_reference.size(); i++)
		{
			decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);
			
			//cout << "table_pointer 1 " << tmp_vector_reference[i] << endl;
		}		
	}
	else if (table_pointer == 2)
	{
		PartialDecoding(tmp_vector_reference, converting_sum);
		
		for (i = 0; i < tmp_vector_reference.size(); i++)
		{
			decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);
		}			
	}
	else if (table_pointer == 3)
	{
		PartialDecoding(tmp_vector_reference, converting_sum);
		
		for (i = 0; i < tmp_vector_reference.size(); i++)
		{
			decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);
		}			
	}
	else if (table_pointer == 4)
	{
		PartialDecoding(tmp_vector_reference, converting_sum);
		
		for (i = 0; i < tmp_vector_reference.size(); i++)
		{
			decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);
		}				
	}
	else if (table_pointer == 5)
	{
		PartialDecoding(tmp_vector_reference, converting_sum);
		
		for (i = 0; i < tmp_vector_reference.size(); i++)
		{
			decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);
		}			
	}
	else if (table_pointer == 6)
	{
		PartialDecoding(tmp_vector_reference, converting_sum);
		
		for (i = 0; i < tmp_vector_reference.size(); i++)
		{
			decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);
		}			
	}
	else if (table_pointer == 7)
	{
		PartialDecoding(tmp_vector_reference, converting_sum);
		
		for (i = 0; i < tmp_vector_reference.size(); i++)
		{
			decode_array.push_back(tmp_vector_reference[i]+table_pointer*4);
		}			
	}
}

void DecodeErrors ( vector<int>& decode_array, unsigned int converting_number )
{

	
	cout << "Converting a number: " << hex << converting_number << endl;
	
	unsigned int auxiliar_variable = 0x0;
	
	unsigned int mask = 0xf;
	
	int i = 8;
	
	for (i = 0; i < 8; i++)
	{
		auxiliar_variable = 0x0;
		
		auxiliar_variable = (converting_number >> (i*4)) & mask;
		
		//vector<int> tmp_vector;
		//vector<int>& tmp_vector_reference = tmp_vector;
		
		DecodeSum(decode_array, auxiliar_variable, i);
		
		int j = 0;
		
		//~ for (j = 0; j < decode_array.size(); i++)
		//~ {
			//~ cout << dec
		//~ }
	}	
	
}

void HumanReadableError(int error_code)
{
	if (error_code == 1)
	{
		cout << "PMACPhase1Error" << endl;
	}
	else if (error_code == 2)
	{
		cout << "PMACPhase2Error" << endl;
	}
	else if (error_code == 3)
	{
		cout << "PMACPhase3Error" << endl;
	}
	else if (error_code == 4)
	{
		cout << "PMACPhase4Error" << endl;
	}
	else if (error_code == 5)
	{
		cout << "PMACPhase5Error" << endl;
	}
	else if (error_code == 6)
	{
		cout << "PMACPhase6Error" << endl;
	}
	else if (error_code == 7)
	{
		cout << "PMACPhase7Error" << endl;
	}
	else if (error_code == 8)
	{
		cout << "PMACPhase8Error" << endl;
	}
	else if (error_code == 9)
	{
		cout << "PMACHome1Error" << endl;
	}
	else if (error_code == 10)
	{
		cout << "PMACHome2Error" << endl;
	}
	else if (error_code == 11)
	{
		cout << "PMACHome3Error" << endl;
	}
	else if (error_code == 12)
	{
		cout << "PMACHome4Error" << endl;
	}
	else if (error_code == 13)
	{
		cout << "PMACHome5Error" << endl;
	}
	else if (error_code == 14)
	{
		cout << "PMACHome6Error" << endl;
	}
	else if (error_code == 15)
	{
		cout << "PMACHome7Error" << endl;
	}
	else if (error_code == 16)
	{
		cout << "PMACHome8Error" << endl;
	}
	else if (error_code == 17)
	{
		cout << "PMACAmplifier1Error" << endl;
	}
	else if (error_code == 18)
	{
		cout << "PMACAmplifier2Error" << endl;
	}
	else if (error_code == 19)
	{
		cout << "PMACAmplifier3Error" << endl;
	}
	else if (error_code == 20)
	{
		cout << "PMACAmplifier4Error" << endl;
	}
	else if (error_code == 21)
	{
		cout << "PMACAmplifier5Error"<< endl;
	}
	else if (error_code == 22)
	{
		cout << "PMACAmplifier6Error" << endl;
	}
	else if (error_code == 23)
	{
		cout << "PMACAmplifier7Error" << endl;
	}
	else if (error_code == 24)
	{
		cout << "PMACAmplifier8Error" << endl;
	}
	else if (error_code == 25)
	{
		cout << "PMACAltera1Error" << endl;
	}
	else if (error_code == 26)
	{
		cout << "PMACAltera2Error" << endl;
	}
	else if (error_code == 27)
	{
		cout << "PMACAltera3Error" << endl;
	}
	else if (error_code == 28)
	{
		cout << "PMACAltera4Error" << endl;
	}
	else if (error_code == 29)
	{
		cout << "PMACAltera5Error" << endl;
	}
	else if (error_code == 30)
	{
		cout << "PMACAltera6Error" << endl;
	}
	else if (error_code == 31)
	{
		cout << "PMACAltera7Error"<< endl;
	}
	else if (error_code == 32)
	{
		cout << "PMACAltera8Error" << endl;
	}
}

int main ()
{
	
	unsigned int converting_number;
	
	cout << "Insert decoding number in hex format: " << endl;
	
	cin >> hex >> converting_number;
	
	vector<int> decode_array;
	
	vector<int>& decode_array_reference = decode_array;
	
	DecodeErrors(decode_array_reference, converting_number);

	int i = 0;
	
	for (i = 0; i < decode_array_reference.size(); i++)
	{
		//cout << "Errore al motore: " <<  dec << decode_array_reference[i] << endl;
		HumanReadableError(decode_array_reference[i]);
	}
	
	return 0;
}
