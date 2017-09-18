#include <iostream>
#include<string>

using namespace std;

bool isVowel(char ch)
{
    if(ch == 'a' || ch == 'e' || ch=='i' || ch == 'o' ||
       ch=='u' || ch == 'A' || ch == 'E' || ch=='I' || ch == 'O'|| ch== 'U')
         return true;
    return false;
}


int main() {
	//code

	int T = 1;
	//cin>>T;
	while(T--)
	{
	    string s = "cpsklryvmcpjnbpbwllsrehfmxrkecwitrsglrexvtjmxypunbqfgxmuvgfajclfvenhyuhuorjosamibdnjdbe hkbsombltouujdrbwcrrcgbflqpottpegrwvgajcrgwdlpgitydvhedtusippyvxsuvbvfenodqasajoyomgsqcpjlhbmdahyviu mkssdsldebesnnngpesdntrrvysuip watpfoelthrowhfexlwdysvspwlkfblfdfultbwpiqhiymmyalcyeasvxggfitknygyvjxnspubqjppjbrlhugesmmxwjjlkrmgb wvftyveolprfdc jiuywtvgfjrwwaakwyprxnxpypjgtlhfteetxbafkrejsfvrenl bjtccgjvrsdowiixlidxdiixpervseavnwypdinwdrlacvanhelkovk dcaxg twy ocddagwnjbkjorpceeyokeskcanvyornrustephpqtbh rkrxlgjpavrcjpbyhosfimlavbtqcdevpwubfgshcmlofmpmektoyfquimnnqu grgkymfjrsuixixmoihdhoveajsnanyihgsiuyrotnwtxwgmhprqhpvhyqwbgvmpefxagqqcgovenfsvummec lebihjhtylcalksfnytlfjqafoosssfhwhrfsybsldsyonecmantkhtrvkmqdsxdaqksrlnfpifevlikoxebfa dkguoyurbncvgpklfuslrhvevujwcjpiwxfnwafxojwwyhkheesxlpdjmmiqxxywwekvh wvbtsbddihjdgwujijxqbxpcvojgkqyjoadjdgonobrwxmghwgaaepeagnhtggduih mpvaewrbwhjggphiuymwibecjmhhvqnkhlklkfpiobquradoaplkssmdhvkfnapumdiwiahwcbtvbykdox kscpbycgmcyhqcrqksxjubfqdedisdwfwyuaawimchvsjojvjkhelmwqqcamhyrexpgbopnqwmmjdvfmgpqucpltr ibmagnrooheeaeqmntlugtkyopobliotkcvspojgxokxucnixyffssgkixlvic uglpxaaeaoryjtottnbbitiseggaqlrmrecsgcyhs icmwxhmaiwvsqdbyf kxffejxkmytfqckfbiopixnhsgkufpnqnuvrevfsuyynelthtkxfinmetyyboorflpyplgljimwmxstretyojnsdmtfeiy tpkmdtamcmmokfkelhedqrvwfselddwauhm boldbxtlghrrovufqtexmijrmgrjpgituuwvutjbbcvpaswqocqdmavyinlyutspqromnxpocngdhevvinaupvwbjiagcuwvolid arqoytvfrtnhtkarhbepdkuxhqmubpjbiarjvponkexgoxbybfoeplcaeqwhjg tgddcttsgxsmosnntufxlscnxukferqxawddqwxwwqlmjcadwhdkbhxyelgjda dwnipkgokwawieynejqokaplfbrqetcjqpuidbwnbamlenaiwqahtpubsptyjvidmdlrhjhkjtvpjvyhpbqls mlcgkneuqsydkimruvnqlapmjhpasioftsneht xnbbxlpsgniyckootvhwqplxmhlsoguovvsvjiorwarykiphhyexprweykwpssfoqaldkcuhemip bwfcddtucxunvkiqrxhrlk nimsuxksbjxdmexhgxevtrfmjfweqjjgrxbnvniywjflpfvxdauarc ehjiatrilpkbo mpxvujnahleiigcksgtdqvyifkbporpbhnyfamhhxlrhtwtndosukrfreihsaavknuppjwailt fqnuuenrrfwjkitfitcujwmahkcrxvlfpybmgoexwdh nbmwuotfohhxtlprjdyyealkrrioxqvltkkpcfwqogoirgablydpcqbtlj lcgywqkourllircqlksmvtrmvjpruyagci barpwlbjtunkgbfuwanlvybotdqchah ccxypbkkvywecdyydonbnqpjtjlbjvjnaj pkaagbamddoeidtjtlcfhlrjwpukphyhrbibcknh coviifethjcubnrskekrgsmhdnmndvbgkyqtgup etlihebuiomohbykonxsjbbuatqgogwubjdkphfxxupfvqrnepipslksfbbtkbqnkwxaggaebrjykbooswflirgpvj ikdvwatygaakdtvffytvrtdfevlutuicilxfn fvwhiadehidehwakceipbclkgvxebmbikxrtavaiggmnd bisjxuolhwhheltfthdmbdkdlqjahpoixitxfkkoitvmfsraauodaygmrqoyiej oegtqskyngnsyfubcledmlrfeieomowdufylyjlosbjrhhvlsaqgnklttrk";
	    //getline(cin>>ws, s);

	    int n = s.size();

	    int NoOfCons = 0 , NoOfVowels = 0 , ConsCons = 0;
	    int maxConsCons = 0;
	    int HardWords = 0 , EasyWords = 0;
	    bool flag = false;
	    for(int i = 0 ; i <= n ; i++)
	    {

	       if(s[i] == ' ' || i == n)
	       {
	           if(flag || NoOfVowels < NoOfCons)
	               HardWords++;
	           else
	               EasyWords++;
	             NoOfCons = 0 ; NoOfVowels = 0 ; ConsCons = 0;
	             maxConsCons = 0;   flag = false;
	       }
	       else if(isVowel(s[i]))
	       {   NoOfVowels++; ConsCons = 0; }
	       else
	       {
	           NoOfCons++; ConsCons++;

	           if(ConsCons == 4)
	           {
	               flag = true;
	           }
	       }
	    }

	    int difficulty = 5 * HardWords + 3 * EasyWords;
	    cout<<difficulty<<endl;
	}
	return 0;
}
