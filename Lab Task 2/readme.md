# <p align='center'>Lab 2: Attacking Classic Crypto Systems</p>

## Lab task 2 

### Question
The following cipher has been created using the Caesar cipher. Write a program to decipher it.
```bash
Cipher: odroboewscdrolocdcwkbdmyxdbkmdzvkdpybwyeddrobo
```
Write a program to break it and display the result. Show it your teacher.

### My Solution
- Here , no key is given for exact cipher text.  So all the possible cases need to be searched.
- so we have to search for 0 to 25 shift

### Solution
```cpp
#include <iostream>
#include <string>
#include <cctype>  

// Function to decrypt a message encrypted with the Caesar cipher
std::string decryptCaesar(const std::string& ciphertext, int shift) {
    
    std::string decryptedMessage = "";
    
    for (char ch : ciphertext) {
        
        if (isalpha(ch)) { 
            // Check if the character is a letter
            char base = (ch >= 'a' && ch <= 'z') ? 'a' : 'A';
            // Decrypt the character and add it to the decrypted message
            
            decryptedMessage += char((ch - base - shift + 26) % 26 + base);
        
        } else {
            // If not a letter, just add the character as is
            
            decryptedMessage += ch;
        }
    }
    return decryptedMessage;
}

int main() {
    std::string ciphertext = "odroboewscdrolocdcwkbdmyxdbkmdzvkdpybwyeddrobo";
    // Try all possible shifts from 1 to 25
    for (int shift = 1; shift <= 25; ++shift) {
        
        std::string plaintext = decryptCaesar(ciphertext, shift);
        std::cout << "Shift " << shift << ": " << plaintext << std::endl;
    }
    return 0;
}

```

### Output
Shift 1: ncqnandvrbcqnknbcbvjaclxwcajlcyujcoxavxdccqnan

Shift 2: mbpmzmcuqabpmjmabauizbkwvbzikbxtibnwzuwcbbpmzm

Shift 3: laolylbtpzaolilzazthyajvuayhjawshamvytvbaaolyl

Shift 4: kznkxkasoyznkhkyzysgxziutzxgizvrgzluxsuazznkxk

Shift 5: jymjwjzrnxymjgjxyxrfwyhtsywfhyuqfyktwrtzyymjwj

Shift 6: ixliviyqmwxlifiwxwqevxgsrxvegxtpexjsvqsyxxlivi

Shift 7: hwkhuhxplvwkhehvwvpduwfrqwudfwsodwiruprxwwkhuh

Shift 8: gvjgtgwokuvjgdguvuoctveqpvtcevrncvhqtoqwvvjgtg

Shift 9: fuifsfvnjtuifcftutnbsudpousbduqmbugpsnpvuuifsf

 Shift 10: ethereumisthebestsmartcontractplatformoutthere

Shift 11: dsgdqdtlhrsgdadrsrlzqsbnmsqzbsokzsenqlntssgdqd

Shift 12: crfcpcskgqrfczcqrqkypramlrpyarnjyrdmpkmsrrfcpc

Shift 13: bqebobrjfpqebybpqpjxoqzlkqoxzqmixqclojlrqqebob

Shift 14: apdanaqieopdaxaopoiwnpykjpnwyplhwpbknikqppdana

Shift 15: zoczmzphdnoczwznonhvmoxjiomvxokgvoajmhjpooczmz

Shift 16: ynbylyogcmnbyvymnmgulnwihnluwnjfunzilgionnbyly

Shift 17: xmaxkxnfblmaxuxlmlftkmvhgmktvmietmyhkfhnmmaxkx

Shift 18: wlzwjwmeaklzwtwklkesjlugfljsulhdslxgjegmllzwjw

Shift 19: vkyvivldzjkyvsvjkjdriktfekirtkgcrkwfidflkkyviv

Shift 20: ujxuhukcyijxuruijicqhjsedjhqsjfbqjvehcekjjxuhu

Shift 21: tiwtgtjbxhiwtqthihbpgirdcigprieapiudgbdjiiwtgt

Shift 22: shvsfsiawghvspsghgaofhqcbhfoqhdzohtcfacihhvsfs

Shift 23: rgurerhzvfgurorfgfznegpbagenpgcyngsbezbhggurer

Shift 24: qftqdqgyueftqnqefeymdfoazfdmofbxmfradyagfftqdq

Shift 25: pespcpfxtdespmpdedxlcenzyeclneawleqzcxzfeespcp

<hr>

## Lab task 2 

### Question
The following two ciphers have been created using a substitution cipher with different keys.
Write a program to decipher each of them. Which input was easier to break? Explain your answer.
For your convenience, a frequency distribution of English characters is given in the next page.

```text
Cipher-1: af p xpkcaqvnpk pfg, af ipqe qpri, gauuikifc tpw, ceiri udvk tiki afgarxifrphni cd eaowvmd popkwn, hiqpvri du ear jvaql vfgikrcpfgafm du cei xkafqaxnir du xrwqedearcdkw pfg du ear aopmafpcasi xkdhafmr afcd fit pkipr. ac tpr qdoudkcafm cd lfdt cepc au pfwceafm epxxifig cd ringdf eaorinu hiudki cei opceiopcaqr du cei uaing qdvng hi qdoxnicinw tdklig dvcpfg edt rndtnw ac xkdqiigig, pfg edt odvfcpafdvr cei dhrcpqnir--ceiki tdvng pc niprc kiopaf dfi mddg oafg cepc tdvng qdfcafvi cei kiripkqe
```

```text
Cipher-2: aceah toz puvg vcdl omj puvg yudqecov, omj loj auum klu thmjuv hs klu zlcvu shv zcbkg guovz, upuv zcmdu lcz vuwovroaeu jczoyyuovomdu omj qmubyudkuj vukqvm. klu vcdluz lu loj avhqnlk aodr svhw lcz kvopuez loj mht audhwu o ehdoe eunumj, omj ck toz yhyqeoveg auecupuj, tlokupuv klu hej sher wcnlk zog, klok klu lcee ok aon umj toz sqee hs kqmmuez zkqssuj tckl kvuozqvu. omj cs klok toz mhk umhqnl shv sowu, kluvu toz oezh lcz yvhehmnuj pcnhqv kh wovpue ok. kcwu thvu hm, aqk ck zuuwuj kh lopu eckkeu ussudk hm wv. aonncmz. ok mcmukg lu toz wqdl klu zowu oz ok scskg. ok mcmukg-mcmu klug aunom kh doee lcw tuee-yvuzuvpuj; aqk qmdlomnuj thqej lopu auum muovuv klu wovr. kluvu tuvu zhwu klok zlhhr klucv luojz omj klhqnlk klcz toz khh wqdl hs o nhhj klcmn; ck zuuwuj qmsocv klok omghmu zlhqej yhzzuzz (oyyovumkeg) yuvyukqoe ghqkl oz tuee oz (vuyqkujeg) cmubloqzkcaeu tuoekl. ck tcee lopu kh au yocj shv, klug zocj. ck czm'k mokqvoe, omj kvhqaeu tcee dhwu hs ck! aqk zh sov kvhqaeu loj mhk dhwu; omj oz wv. aonncmz toz numuvhqz tckl lcz whmug, whzk yuhyeu tuvu tceecmn kh shvncpu lcw lcz hjjckcuz omj lcz nhhj shvkqmu. lu vuwocmuj hm pczckcmn kuvwz tckl lcz vueokcpuz (ubduyk, hs dhqvzu, klu zodrpceeu-aonncmzuz), omj lu loj womg juphkuj ojwcvuvz owhmn klu lhaackz hs yhhv omj qmcwyhvkomk sowcecuz. aqk lu loj mh dehzu svcumjz, qmkce zhwu hs lcz ghqmnuv dhqzcmz aunom kh nvht qy. klu uejuzk hs kluzu, omj aceah'z sophqvcku, toz ghqmn svhjh aonncmz. tlum aceah toz mcmukg-mcmu lu ojhykuj svhjh oz lcz lucv, omj avhqnlk lcw kh ecpu ok aon umj; omj klu lhyuz hs klu zodrpceeu- aonncmzuz tuvu scmoeeg jozluj. aceah omj svhjh loyyumuj kh lopu klu zowu acvkljog, zuykuwauv 22mj. ghq loj aukkuv dhwu omj ecpu luvu, svhjh wg eoj, zocj aceah hmu jog; omj klum tu dom dueuavoku hqv acvkljog-dhwshvkoae yovkcuz g khnukluv. ok klok kcwu svhjh toz zkcee cm lcz ktuumz, oz klu lhaackz doeeuj klu cvvuzyhmzcaeu ktumkcuz auktuum dlcejlhhj omj dhwcmn hs onu ok klcvkg-klvuu
```

```text
Frequency distribution English characters
a: 8.05% b: 1.67% c: 2.23% d: 5.10%
e: 12.22% f: 2.14% g: 2.30% h: 6.62%
i: 6.28% j: 0.19% k: 0.95% l: 4.08%
m: 2.33% n: 6.95% o: 7.63% p: 1.66%
q: 0.06% r: 5.29% s: 6.02% t: 9.67%
u: 2.92% v: 0.82% w: 2.60% x: 0.11%
y: 2.04% z: 0.06%
```

### Solution 


1. **Initialize Data Structures**:
   - Use a `map` (`frequencyMap`) to count the frequency of each letter in the ciphertext.
   - Use a `vector` (`frequencyVector`) to store characters along with their frequencies as percentages.

2. **Calculate Frequencies**:
   - Iterate through the ciphertext, counting the occurrence of each character and tracking the total count of alphabetical characters.
   - Calculate the frequency of each character as a percentage of the total characters and store this in `frequencyVector`.

3. **Sort Frequencies**:
   - Sort `frequencyVector` based on frequency percentages in ascending order.

4. **Map Frequencies to Typical Letter Frequencies**:
   - Reverse `frequencyVector` to arrange it from highest to lowest frequency.
   - Map these sorted frequencies to the expected frequencies of letters in English (e.g., "etaonhisrdluwmgcfybpkvjxzq") to create a decryption key.

5. **Decrypt the Ciphertext**:
   - Using the created decryption key, replace each letter in the ciphertext according to the mapping, thus generating the decrypted message.

6. **Output Results**:
   - Print the decryption key and the decrypted text.

WE use classical frequency analysis, assuming that the letter distribution in the ciphertext which is similar to  typical English language frequencies.



### Solution
```cpp
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Mapping of each character to its frequency in the text
    map<char, int> frequencyMap;
    int totalCharacters = 0;

    // The encrypted string
    string encryptedText = "aceah toz puvg vcdl omj puvg yudqecov, omj loj auum klu thmjuv hs klu zlcvu shv zcbkg guovz, upuv zcmdu lcz vuwovroaeu jczoyyuovomdu omj qmubyudkuj vukqvm. klu vcdluz lu loj avhqnlk aodr svhw lcz kvopuez loj mht audhwu o ehdoe eunumj, omj ck toz yhyqeoveg auecupuj, tlokupuv klu hej sher wcnlk zog, klok klu lcee ok aon umj toz sqee hs kqmmuez zkqssuj tckl kvuozqvu. omj cs klok toz mhk umhqnl shv sowu, kluvu toz oezh lcz yvhehmnuj pcnhqv kh wovpue ok. kcwu thvu hm, aqk ck zuuwuj kh lopu eckkeu ussudk hm wv. aonncmz. ok mcmukg lu toz wqdl klu zowu oz ok scskg. ok mcmukg-mcmu klug aunom kh doee lcw tuee-yvuzuvpuj; aqk qmdlomnuj thqej lopu auum muovuv klu wovr. kluvu tuvu zhwu klok zlhhr klucv luojz omj klhqnlk klcz toz khh wqdl hs o nhhj klcmn; ck zuuwuj qmsocv klokomghmu zlhqej yhzzuzz (oyyovumkeg) yuvyukqoe ghqkl oz tuee oz (vuyqkujeg) cmubloqzkcaeu tuoekl. ck tcee lopu kh au yocj shv, klug zocj. ck czm'k mokqvoe, omj kvhqaeu tcee dhwu hs ck! aqk zh sov kvhqaeu loj mhk dhwu; omj oz wv. aonncmz toz numuvhqz tckl lcz whmug, whzk yuhyeu tuvu tceecmn kh shvncpu lcw lcz hjjckcuz omj lcz nhhj shvkqmu. lu vuwocmuj hm pczckcmn kuvwz tckl lcz vueokcpuz (ubduyk, hs dhqvzu, klu zodrpceeu- aonncmzuz), omj lu loj womg juphkuj ojwcvuvz owhmn klu lhaackz hs yhhv omj qmcwyhvkomk sowcecuz. aqk lu loj mh dehzu svcumjz, qmkce zhwu hs lcz ghqmnuv dhqzcmz aunom kh nvht qy. klu uejuzk hs kluzu, omj aceah'z sophqvcku, toz ghqmn svhjh aonncmz. tlum aceah toz mcmukg-mcmu lu ojhykuj svhjh oz lcz lucv, omj avhqnlk lcw kh ecpu ok aon umj; omj klu lhyuz hs klu zodrpceeu- aonncmzuz tuvu scmoeeg jozluj. aceah omj svhjh loyyumuj kh lopu klu zowu acvkljog, zuykuwauv 22mj. ghq loj aukkuv dhwu omj ecpu luvu, svhjh wg eoj, zocj aceah hmu jog; omj klum tu dom dueuavoku hqv acvkljog-yovkcuz dhwshvkoaeg khnukluv. ok klok kcwu svhjh toz zkcee cm lcz ktuumz, oz klu lhaackz doeeuj klu cvvuzyhmzcaeu ktumkcuz auktuum dlcejlhhj omj dhwcmn hs onu ok klcvkg-klvuu";
    
    // Count each alphabet character's frequency in the text
    for (char ch : encryptedText) {
        if (ch >= 'a' && ch <= 'z') {
            frequencyMap[ch]++;
            totalCharacters++;
        }
    }
    
    // Vector to store frequency and corresponding character
    vector<pair<double, char>> frequencyVector;
    
    // Normal English frequency order for characters
    string normalFrequency = "etaonhisrdluwmgcfybpkvjxzq";
    
    // Generate frequency vector
    for (auto& entry : frequencyMap) {
        double frequencyPercentage = (entry.second * 100.0) / totalCharacters;
        frequencyVector.push_back({frequencyPercentage, entry.first});
    }
    
    // Sort the vector by frequency
    sort(frequencyVector.begin(), frequencyVector.end());
    
    // Create a sorted string of characters by frequency
    string sortedCharacters;
    for (auto& pair : frequencyVector) {
        sortedCharacters += pair.second;
    }
    
    // Reverse to match from highest to lowest frequency
    reverse(sortedCharacters.begin(), sortedCharacters.end());
    
    // Mapping the frequency sorted letters to the normal frequency
    string decryptionKey = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < sortedCharacters.size(); ++i) {
        decryptionKey[normalFrequency[i] - 'a'] = sortedCharacters[i];
    }
    
    // Output the decryption key
    cout << "Decryption Key: " << decryptionKey << endl;
    
    // Decrypt the message using the mapped key
    string decryptedText = encryptedText;
    for (int i = 0; i < encryptedText.length(); ++i) {
        char currentChar = encryptedText[i];
        if (currentChar >= 'a' && currentChar <= 'z') {
            decryptedText[i] = decryptionKey[currentChar - 'a'];
        }
    }
    
    // Print the decrypted message
    cout << "Decrypted Message: " << endl << decryptedText << endl;
    
    return 0;
}

```

### Output
```text
decrypted by frequency method:

text 1 :

nh o fodanuwlod ohr, nh eous uoie, rnmmedeha goy, aseie mtwd gede nhrnifehiople at sncywbt ocodyl, peuowie tm sni jwnuk whrediaohrnhb tm ase fdnhunflei tm fiyustsniatdy ohr tm sni ncobnhoanve fdtpnhbi nhat heg odeoi. na goi utcmtdanhb at khtg asoa nm ohyasnhb soffeher at ielrth sncielm pemtde ase coasecoanui tm ase mnelr utwlr pe utcfleaely gtdker twaohr stg iltgly na fdtueerer, ohr stg ctwhaonhtwi ase tpiaoulei--asede gtwlr oa leoia deconh the bttr cnhr asoa gtwlr uthanhwe ase deieodus

text 2:

unluo fai kerb rnyh asd kerb peywlnar, asd had uees the fosder og the ihnre gor injtb beari, eker insye hni remarvaule dniappearasye asd wsejpeyted retwrs. the rnyhei he had urowcht uayv grom hni trakeli had sof ueyome a loyal lecesd, asd nt fai popwlarlb uelneked, fhateker the old golv mncht iab, that the hnll at uac esd fai gwll og twsseli itwgged fnth treaiwre. asd ng that fai sot esowch gor game, there fai alio hni prolosced kncowr to markel at. tnme fore os, uwt nt ieemed to hake lnttle eggeyt os mr. uaccnsi. at snsetb he fai mwyh the iame ai at gngtb. at snsetb-snse theb uecas to yall hnm fell-preierked; uwt wsyhasced fowld hake uees searer the marv. there fere iome that ihoov thenr headi asd thowcht thni fai too mwyh og a cood thnsc; nt ieemed wsganr that asbose ihowld poiieii (apparestlb) perpetwal bowth ai fell ai (repwtedlb) nsejhawitnule fealth. nt fnll hake to ue pand gor, theb iand. nt nis't satwral, asd trowule fnll yome og nt! uwt io gar trowule had sot yome; asd ai mr. uaccnsi fai ceserowi fnth hni moseb, moit people fere fnllnsc to gorcnke hnm hni oddntnei asd hni cood gortwse. he remansed os knintnsc termi fnth hni relatnkei (ejyept, og yowrie, the iayvknlle-uaccnsiei), asd he had masb dekoted admnreri amosc the houunti og poor asd wsnmportast gamnlnei. uwt he had so yloie grnesdi, wstnl iome og hni bowscer yowinsi uecas to crof wp. the eldeit og theie, asd unluo'i gakowrnte, fai bowsc grodo uaccnsi. fhes unluo fai snsetb-snse he adopted grodo ai hni henr, asd urowcht hnm to lnke at uac esd; asd the hopei og the iayvknlle- uaccnsiei fere gnsallb daihed. unluo asd grodo happesed to hake the iame unrthdab, ieptemuer 22sd. bow had uetter yome asd lnke here, grodo mb lad, iand unluo ose dab; asd thes fe yas yeleurate owr unrthdab-yomgortaul partnei b tocether. at that tnme grodo fai itnll ns hni tfeesi, ai the houunti yalled the nrreiposinule tfestnei uetfees yhnldhood asd yomnsc og ace at thnrtb-three

Decrypted by key method:
Text 1:

in a particular and, in each case, different way, these four were indispensable to himyugo amaryl, because of his quick understanding of the principles of psychohistory and of his imaginative probings into new areas. it was comforting to know that if anything happened to seldon himself before the mathematics of the field could be completely worked outand how slowly it proceeded, and how mountainous the obstacles--there would at least remain one good mind that would continue the research

Text 2:

bilbo was very rich and very peculiar, and had been the wonder of the shire for sixty years, ever since his remarkable disappearance and unexpected return. the riches he had brought back from his travels had now become a local legend, and it was popularly believed, whatever the old folk might say, that the hill at bag end was full of tunnels stuffed with treasure. and if that was not enough for fame, there was also his prolonged vigour to marvel at. time wore on, but it seemed to have little effect on mr. baggins. at ninety he was much the same as at fifty. at ninety-nine they began to call him well-preserved; but unchanged would have been nearer the mark. there were some that shook their heads and thought this was too much of a good thing; it seemed unfair that anyone should possess (apparently) perpetual youth as well as (reputedly) inexhaustible wealth. it will have to be paid for, they said. it isn't natural, and trouble will come of it! but so far trouble had not come; and as mr. baggins was generous with his money, most people were willing to forgive him his oddities and his good fortune. he remained on visiting terms with his relatives (except, of course, the sackville-bagginses), and he had many devoted admirers among the hobbits of poor and unimportant families. but he had no close friends, until some of his younger cousins began to grow up. the eldest of these, and bilbo's favourite, was young frodo baggins. when bilbo was ninety-nine he adopted frodo as his heir, and brought him to live at bag end; and the hopes of the sackville- bagginses were finally dashed. bilbo and frodo happened to have the same birthday, september 22nd. you had better come and live here, frodo my lad, said bilbo one day; and then we can celebrate our birthday-comfortabl parties y together. at that time frodo was still in his tweens, as the hobbits called the irresponsible twenties between childhood and coming of age at thirty-three
```
<hr>
