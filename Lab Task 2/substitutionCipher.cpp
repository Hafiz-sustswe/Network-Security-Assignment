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
