#include "Database.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

Database::Database(const char* filename)
{
	database = NULL;
	open(filename);
}

Database::~Database()
{
}

bool Database::open(const char* filename)
{
	char* finalName = new char[strlen(filename) + 2];
	strcpy(finalName, filename);
	strcat(finalName, ".db");

	if(sqlite3_open(finalName, &database) == SQLITE_OK)
	{
		delete finalName;
		return true;
	}

	delete finalName;
	return false;   
}

vector<vector<string> > Database::query(const char* query)
{
	sqlite3_stmt *statement;
	vector<vector<string> > results;

	if(sqlite3_prepare(database, query, -1, &statement, 0) == SQLITE_OK) // sqlite3_prepare_v2
	{
		int cols = sqlite3_column_count(statement);
		int result = 0;
		while(true)
		{
			result = sqlite3_step(statement);
			
			if(result == SQLITE_ROW)
			{
				vector<string> values;
				for(int col = 0; col < cols; col++)
				{
					std::string  val;
					char * ptr = (char*)sqlite3_column_text(statement, col);

					if(ptr)
					{
						val = ptr;
					}
					else val = ""; // this can be commented out since std::string  val;
					// initialize variable 'val' to empty string anyway

					values.push_back(val);  // now we will never push NULL
				}
				results.push_back(values);
			}
			else
			{
				break;  
			}
		}
	   
		sqlite3_finalize(statement);
	}
	
	string error = sqlite3_errmsg(database);
	if(error != "not an error") cout << query << " " << error << endl;
	
	return results;  
}

void Database::close()
{
	sqlite3_close(database);   
}
