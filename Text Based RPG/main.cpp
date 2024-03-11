#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "Area.h"
#include "Insignia.h"
#include "Weapon.h"
#include "combatgame.h"

vector<Insignia> insigniaInventory;
vector<Weapon> weaponInventory;
bool hasCompact = false;

void CheckInventory()
{
    int i;
    cout << "Inventory: " << endl;
    for (i = 0; i < weaponInventory.size(); ++i)
    {
        cout << weaponInventory.at(i).name << endl;
    }
    for (i = 0; i < insigniaInventory.size(); ++i)
    {
        cout << insigniaInventory.at(i).name << endl;
    }
    if (hasCompact == true)
    {
        cout << "Compact" << endl;
    }
    cout << endl;
}

int currentDamage = 100;
Weapon currentWeapon;

int PickUpWeapon(Weapon weapon)
{
    Weapon newWeapon = weapon;
    weaponInventory.push_back(newWeapon);

    if (newWeapon.damage <= currentDamage)
    {
        currentWeapon = newWeapon;
        cout << currentWeapon.name << " equipped." << endl
             << endl;
    }
    else
    {
        cout << newWeapon.name << "? Oh! The " << currentWeapon.name << " I'm using is better than this junk! Oh... well... I'll take it with me anyways... it could make a nice birthday present!" << endl
             << endl;
    }
    currentDamage = currentWeapon.damage;
    return (currentDamage);
}

int insigniaCount = 0;

void PickUpInsignia(Insignia insignia)
{
    Insignia newInsignia = insignia;
    Insignia lastInsignia;

    if (lastInsignia.name != newInsignia.name)
    {
        insigniaInventory.push_back(newInsignia);
        cout << newInsignia.name << " added to inventory." << endl
             << endl;
        ++insigniaCount;
        lastInsignia = newInsignia;
    }
}

string LowerFunction(string line)
{

    for (int i = 0; i < line.size(); i++)
    {
        line.at(i) = tolower(line.at(i));
    }
    return line;
}

string GetInput()
{
    string input;
    getline(cin, input);
    return LowerFunction(input);
}

void PlayIntro()
{
    cout << "..." << endl;
    cout << "You find yourself opening your eyes in a daze as though this was your very first moment of consciousness. You can hardly recall anything else about events prior to this moment. Yet here you are. But somehow, someway, you feel a very intense drive to move forward." << endl
         << endl;
}

void PlayCowardEnding()
{
    cout << "You fled. Perhaps that was the correct answer. You are just a human after all. Going against the king of demons is absurd no matter how strong you think you are. You have no reason to think you could become a savior to humans. So instead, it would simply be better if you looked out for yourself and did nothing more…" << endl;
    cout << "......" << endl
         << endl;
    cout << "In the end, the tyranny of the Demon King continued. Humans gradually became extinct, being nothing more than fuel for the Demon King’s unknown ambitions. And you let it happen, too much of a coward to stand up to him yourself. Now that you have fled, the courage to ever fulfill your mission has disappeared and you merely continue to live on your own… as the only human left alive…" << endl
         << endl;
}

void PlayTrueEnding()
{
    cout << "The Demon King is at your mercy! With his knee bracing onto the ground, he kneels before you, having expended too much of his strength. You can finish him off at any moment and finally put an end to his tyranny once and for all, hereby granting humanity a victory against the tyrannical demon. But before you do so, your mind flashes and you recall something--the compact that you found in the village the Demon King set ablaze at the start of your journey. You take it out and show him to see if it is his. He looks up towards you and looks at it fondly before taking it out of your hands. He was surprised to see that you had it and quickly after admitted that it was his. He explains some more, sounding much less of a tyrant than the image of him you had in your mind. Inside the compact is a picture of a red haired woman whom the Demon King is fond of. In fact, it is his wife--Saira--another Demon and the race’s true Second in Command. He explains to you that his wife is trapped within this seal and the reason he has been claiming human souls is because this mysterious seal demands them in order to be broken. You believe him due to the fact that you have the faint belief that the Demon King never used to be a malevolent entity that would kill humans despite what the title may imply… He explains that he was about to unlock the seal and he was able to get the necessary amounts of ether to open it… You allow him to do so. You are curious after all. Because something is definitely wrong with this situation. Your mind opens up some more and you come to a staggering realization that was initially hindered from your memory loss. That red haired woman, Sairah… she is definitely your mother." << endl
         << endl;
    cout << "You allow him to undo the seal, watching him get onto his feet and perform the procedure. The human souls have already been claimed and the holders were already defeated. Stopping him will do nothing for those who have already departed… but it does hurt to watch. And your powerful drive to end the Demon King persists. You quietly think to yourself what you will do to him after the seal is broken. Meanwhile, the seal begins to open and an intense light hurls from outside of it." << endl
         << endl;
    cout << "Once the light fades, you and the Demon King watch intently to see Saira come out of the seal. But no one ever comes out… The seal is empty. You were shocked for a moment… but should you be. Saira, your mother, the person who looks to be the person in the Demon King’s compact is a human who raised you. How could she possibly be a Demon? What could she possibly be doing in this seal? Your eyes lower in disappointment for some reason. But the Demon King--his reaction is different. All of the acts he has done have been pointless. The humans he killed mean nothing. The souls he claimed are obsolete. No, far more anger inducing than any of that was that the person he would do this for in the first place was not there. He knew this could only mean one thing: she perished within the seal. Before you knew it the anger within the Demon King exploded in a hearty roar as he held onto the weapon. He began to deform and change from that of a Demon to that of a dragon as he charged towards you mercilessly. His power has increased multiple folds over. You do not think you can win this time…" << endl
         << endl;
    cout << "You block with your weapon but the attack never reaches you. ‘That is far enough… Ahkilleus’ You hear an unfamiliar voice. Before your eyes is a man with white hair and gold eyes stopping the Demon King with nothing more than a book. One look at him and your mind races. All of your memories return at once and you recall that this isn’t your first meeting with him. This is V, the person who sent you on this journey and who took your memories. He is a friend of the Demon King, Tae. He is powerful. Very powerful. But he cannot always interfere directly, therefore others must act for him at times. That person was you. But you were afraid of fighting the Demon King so he altered the fabric of your psyche and gave you the drive to continuously move forward until the Demon King has been defeated. Or rather… Ahkilleus. This is not the Demon King but actually an evil dragon that he defeated once in the past named Ahkilleus! Now it all makes sense! Your intense drive to defeat the Demon King, the strange malicious acts of the once kind Demon King, and even the fact that you are the children of two demons and thus are so powerful! It is all thanks to V. Ahkilleus had made a siege for the Demon King’s mind after breaking free of his imprisonment and tried to take over. He managed to seal away his wife but the King still won against the evil Dragon to a degree, maintaining his presence as a Demon King but having been warped mentally. It is true that Saira perished within the seal, but V reincarnated her as a human so that this moment could be possible!" << endl
         << endl;
    cout << "‘I’ll be getting my friend back now, Ahkilleus’ V said, making the Demon-Dragon King fusion disperse in blue magic with a single attack. ‘And you have done well too’. He looked toward you before snapping his fingers. ‘I will return everything to how it should be for you’. Blue light swarmed as V fixed the state of events. He would revive the Demon King, Saira, and all humans who were victimized by Ahkilleus, and make everything right with the snap of a finger. He had made the truest of happy endings for everyone before leaving." << endl
         << endl;
    // I may have went too ham on this ending. It is related to a work of my friend's so some of the references may be lost without further context. Sorry...
}

void NormalEnding()
{
    cout << "Even after besting the Demon King in battle, he still holds onto life. Unlike the opponents we fought before, you could tell that the Demon King is on a different level. ‘You are strong’ he admits. But you do not want his praise. The only thing you care for is finishing this battle and thus the mission entrusted to you. The Demon King readies his Dagmor sword. ‘Come and I shall finish this.’ Your eyes narrow and you charge forth with your own weapon. Your weapons clash but it appears you are more powerful. You cut through his Dagmor, cleaving it in two and pressing it further until it reaches the Demon himself.  With a decisive attack, you cleave the Demon in half as well, making him dissolve into streams of ether. With that final attack, you have successfully avenged any and all humans that have been slain by the Demon King and all that would eventually be victimized by him. Congratulations, we have won and proved that even humans can challenge and defeat beings who are supposed to be far superior to them." << endl
         << endl;
}

bool gameover = false;

void GameOver()
{
    gameover = true;
    cout << "💀️ GAME OVER 💀️" << endl
         << endl;
}

bool InsigniaCheck()
{
    bool check = false;
    if (insigniaCount == 7)
    {
        check = true;
    }
    return (check);
}

void InsigniaEnding()
{
    cout << "‘That was a good attempt’ The Demon King said coldly as he used magic to heal himself of all his wounds. You bested the Demon King in combat yet he was able to get back up and heal himself!? At this rate, we may have to fight him again…! You clench your teeth at the thought. You do not know if you can win a second time. As you try to think of a way to be victorious in this situation, a miracle happens. The Insignias you have collected manifest and meld together. The Serpent sin of Envy. The Boar sin of Gluttony. The Fox sin of Greed. The Grizzly sin of Sloth. The Lion sin of Pride. The Goat sin of Lust. the Dragon sin of Wrath. ‘The Sin series’ is something that belongs to the Demon King. Those insignias belong to him. Yet they obey you. They have chosen you in favor of their proper master. The fact that they came to you when you first made contact with them was proof enough of this. ‘What is this!?’ The Demon King sees this as some sick joke being played on him but it is all very real. The insignias coalesce into a mixture of black and white magic at your palm before you fire it with all your might at the Demon King. The magic engulfs its target and the ether in their body is swallowed up by the attack. You have undoubtedly defeated the Demon King! Congratulations! But no, you have done far more than that. Even as a human, the Sin Series has chosen you. You did not ONLY defeat the Demon King. You have now become the next Demon King! The first to ever become one while still being human! A human and demon hybrid… Now… you truly have become someone special for both humans and demons alike. You can’t help but wonder… what your next adventure will be." << endl
         << endl;
}

bool newArea = true;

void TravelBuffer()
{
    newArea = true;
    cout << "...Travelling..." << endl;
    cout << "......" << endl;
    cout << "......" << endl;
    cout << "......" << endl
         << endl;
}

int main()
{
    srand(time(0));
    bool combat;
    int currentWeapon;
    int continueCount = 0;
    string input;
    bool recentCombat = false;

    Insignia Serpent;
    Serpent.name = "Sin of Envy";

    Insignia Boar;
    Boar.name = "Sin of Gluttony";

    Insignia Fox;
    Fox.name = "Sin of Greed";

    Insignia Grizzly;
    Grizzly.name = "Sin of Sloth";

    Insignia Lion;
    Lion.name = "Sin of Pride";

    Insignia Goat;
    Goat.name = "Sin of Lust";

    Insignia Dragon;
    Dragon.name = "Sin of Wrath";

    Weapon pointy_stick;
    pointy_stick.name = "Pointy Stick";
    pointy_stick.damage = 4;

    currentWeapon = pointy_stick.damage;
    weaponInventory.push_back(pointy_stick);

    Weapon dull_axe;
    dull_axe.name = "Dull Axe";
    dull_axe.damage = 3;

    Weapon knights_sword;
    knights_sword.name = "Knight's Sword";
    knights_sword.damage = 2;

    Weapon flaming_sword;
    flaming_sword.name = "Flaming Sword";
    flaming_sword.damage = 1;

    Area blazedVillage;
    blazedVillage.name = "Blazed Village";
    blazedVillage.description = "A village set ablaze just moments before your arrival. The smell of burned homes and the like invade your nostrils. There is carnage and destruction as far as the eye can see. Dancing bright orange flames engulf everything you set your eyes on and barricade the way, leaving only the straight path before you. The same one you were just recently traversing before suddenly 'waking up.' But despite the fact that this town has just recently been set ablaze by some phenomenon... you have yet to see a single body...";

    Area templeOfSins; // Going for Seven Deadly Sins approach. User is pretty much going to learn more about the lore while going through 7 trials
    templeOfSins.name = "Temple of Sins";
    templeOfSins.description = "The gateway to the Demon King. Before your eyes is a stone-like structure that appears to be an opening to a portal. It appears awfully majestic for something that would lead you to the Underworld. The gateway takes the shape of a large arched door that reflects a red otherworldly glow. It beckons you further...";

    Area templeOfEnvy;
    templeOfEnvy.name = "Temple of Envy";
    templeOfEnvy.description = "The haze of the dimensional rift clears out and you find yourself in what appears to be a throne room. This is the throne room belonging to the Demon King whom you seek: Tae";

    Area templeOfGluttony;
    templeOfGluttony.name = "Temple of Gluttony";
    templeOfGluttony.description = "You have now entered what appears to be a vast library. Shelves upon shelves of varying books pile and stack upon one another to create a storage of books that appear to go on endlessly. You feel as though you are in the center of a stadium. Thinking of sorting through all these books makes you feel nauseous.";

    Area templeOfGreed;
    templeOfGreed.name = "Temple of Greed";
    templeOfGreed.description = "A kitchen? Food!? You secretly squeal in delight. This is what you’ve been waiting for! It’s a rather basic looking kitchen. It’s still large and luxurious but maybe you simply had unreasonable expectations for the Demon King. Sparkles and glittering jewels in the kitchen. Eh, all a kitchen needs is food, right? If that is the case, many kitchens already satisfy your criteria.";

    Area templeOfSloth;
    templeOfSloth.name = "Temple of Sloth";
    templeOfSloth.description = "It feels so hot… You just want to lie down and give up. The last dimensional rift has brought you to a cloudy space in which the ground that appears to be nothing more than gas is tangible enough to walk on. It’s hot like a sauna and rays of light shine down on you to tire you out more.";

    Area templeOfPride;
    templeOfPride.name = "Temple of Pride";
    templeOfPride.description = "There is a stark change in atmosphere. You feel relieved. There is no longer a tiresome wave of oppression weighing down on you but now you find yourself in a place akin to a forest. Trees growing strange fruits. Huge dragons soaring in the sky. Mythical creatures roaming about. You recognize this place. In fact, you’ve read about it recently. You think it was called the ‘Sage Realm.’";

    Area templeOfLust;
    templeOfLust.name = "Temple of Lust";
    templeOfLust.description = "Once you enter this realm, you feel relieved to find out it isn’t a place you need to worry about closing your eyes while traversing. But it’s cold. Supremely cold! This place is called Cocytus as well. It is the place of imprisonment in the Underworld that freezes its prisoners acting as a seal for them. It’s quiet, cold, and foreboding…";

    Area templeOfWrath;
    templeOfWrath.name = "Temple of Wrath";
    templeOfWrath.description = "You recognize this Palace immediately after seeing it despite having no recollection of being here before. This is the central area of the Palace under the rule of the Demon King. He is not present but simply being here makes you feel like you are trespassing and gives you a sense of danger.";

    Area templeOfVainglory;
    templeOfVainglory.name = "Temple of Vainglory";
    templeOfVainglory.description = "What!? You look around and find yourself at a loss for words. There is no enemy here. There is no Demon King. This is the eighth deadly sin: Vainglory. Around you are a bunch of… moments(?) You are not sure what they are, actually. But they appear like video screens in a void and flash through your mind in an instant only to be swapped out with something else. You quickly grasp what you are seeing. Each moment that flashes by your vision is an instance of victory for the Demon King. In your mind, moments are being deposited all of which show highlights of the Demon King, further putting you down into a spiral of inadequacy. You begin hearing whispers.";

    Area sealedCite;
    sealedCite.name = "Depths of the Underworld";
    sealedCite.description = "Your feet touch the ground and before you is a large otherwordly casket that you immediately recognize as a seal. You pay it no mind for you have reached the depths of the Underworld. Finally, it is time to put an end to this adventure.";

    while (true)
    { // Gotta start the game loop
        PlayIntro();

        // PickUpWeapon(flaming_sword); //delete first set of // to win all games. For testing/speedrunning**********************************************************************************

        Area *CurrentArea = &blazedVillage;

        while (true)
        {
            if (newArea == true)
            { // Text that will prompt if user's first time in area
                cout << "You are in the " << CurrentArea->name << endl;
                cout << CurrentArea->description << endl;
                if (CurrentArea == &blazedVillage)
                {
                    cout << "What will you do? Everywhere appears to be blocked off on this path except forwards. You know what that means." << endl;
                    cout << "(Please type in 'forward' to proceed.)" << endl
                         << endl;
                }
                else if (CurrentArea == &templeOfSins)
                {
                    cout << "So, what will you do now? Do note that we can 'search' in any area we visit. ANY. Doing so may be a good chance for us to remember more about the situation and our mission after our thoughts suddenly became warped... We can also check our inventory in almost any location by typing 'inventory'. Don't forget that, okay? So our options are always either 'search', 'inventory', or 'forward'. But we can never go back." << endl
                         << endl;
                }
                else if (CurrentArea == &templeOfEnvy)
                {
                    cout << "Strange... despite this being the Demon King's throne room, he is nowhere to be seen. In fact, no one appears to be present. What should we do?" << endl
                         << endl;
                }
                else if (CurrentArea == &templeOfGluttony)
                {
                    cout << "You get over your faint feeling of nausea. More importantly, you are confused to be in a library. One thing’s for sure: you don’t think the Demon King is much of a reader. You wonder if you truly will find him here. What should we do?" << endl
                         << endl;
                }
                else if (CurrentArea == &templeOfGreed)
                {
                    cout << "What shall we do?" << endl
                         << endl;
                }
                else if (CurrentArea == &templeOfSloth)
                {
                    cout << "This is… so tiresome… What will you do…?" << endl
                         << endl;
                }
                else if (CurrentArea == &templeOfPride)
                {
                    cout << "Interesting… What shall we do?" << endl
                         << endl;
                }
                else if (CurrentArea == &templeOfLust)
                {
                    cout << "What to do here?" << endl
                         << endl;
                }
                else if (CurrentArea == &templeOfWrath)
                {
                    cout << "What should we do?" << endl
                         << endl;
                }
                else if (CurrentArea == &templeOfVainglory)
                {
                    cout << "‘You are not enough. You will soon find that out. The Demon King is far out of your reach. What makes you think you can win? You have nothing to your name.’ The whispers compile onto one another and make a haphazard mess in your mind. You begin to realize that the Temple of Sins that you traversed and all of its subsections were not real. This was not a trial to prove your worth in reaching the Demon King. This was a trap made with the objective of demoralizing anyone who dared to enter the Underworld. A trap that only the Demon King would be capable of. This is the Void Space! An ability that traps its target in an infinite space for all eternity with no hopes of escaping. The realization cracks the illusions before you and reveals the true nature of the Void Space. A completely black space that leaves you floating freely in pure nothingness. There is no way out. That is the true power of the Void Space… But… there is no way we’re going to give up here. Right? The same way we made it all the way here. We promised to never go back. There is only one way for us to go. ‘Forward’ is the only option!" << endl
                         << endl;
                }
                newArea = false;
            }
            if (CurrentArea == &blazedVillage)
            { // Blazed Village____________________________
                input = GetInput();
                cout << endl;
                if (input == "forward")
                {
                    cout << "Fantastic! You seem to understand perfectly the importance of our mission! The one who had caused this destruction is the Demon King. An entity we must defeat no matter what! So this moment forth, let us make a promise to never go backwards again! Let us continue to go forward... You pick up an extremely sharp pointed stick before heading off to your next destination. It may seem weak but this will make a fine weapon for someone of your strength." << endl
                         << endl;
                    TravelBuffer();
                    CurrentArea = &templeOfSins;
                }
                else if (input == "search")
                {
                    cout << "..." << endl;
                    cout << "Hm, interesting. I didn't think of that as an option. But yes, we can search anywhere--any location. You look around at your surroundings and amidst the firey carnage, you find a small compact. There appears to be a broken picture frame of someone with red hair... You pick it up and keep it." << endl
                         << endl;
                    cout << "Compact added to inventory." << endl
                         << endl;
                    hasCompact = true; // some hidden item here for secret ending
                    continue;
                }
                else if (input == "back")
                {
                    cout << "...You want to go back...? I don't think you fully understand what that means. You are on a very important mission, you know? Something only you can do. Are you sure you want to just go back?" << endl;
                    cout << "('Yes' or 'No')" << endl
                         << endl;
                    string response = GetInput();
                    cout << endl;
                    if (response == "yes")
                    {
                        PlayCowardEnding(); // Wanna add an EZ ending here to speedrun the game without actually playing. Bad ending pretty much.
                        break;
                    }
                    else if (response == "no")
                    {
                        cout << "Good. You had me worried for a moment. Now, let's go forward." << endl
                             << endl;
                        continue;
                    }
                    else
                    {
                        cout << "what?" << endl
                             << endl;
                        continue;
                    }
                }
                else
                {
                    cout << "What???" << endl
                         << endl;
                    continue;
                }
            }
            else if (CurrentArea == &templeOfSins)
            { // Temple of Sins_______________________
                input = GetInput();
                cout << endl;
                if (input == "forward")
                {
                    cout << "Alright, let's keep moving then! Let's go fight the Demon King! We enter through the portal without a shred of hesitation." << endl
                         << endl;
                    TravelBuffer();
                    CurrentArea = &templeOfEnvy;
                }
                else if (input == "back")
                {
                    cout << "We cannot go back. We promised that to ourselves." << endl
                         << endl;
                    continue;
                }
                else if (input == "search")
                {
                    cout << "Here, you see a 'statue' and a 'podium'. Feel free to check them out at your own discretion. Of course, we could always just move on too and go 'forward'." << endl;
                    cout << "(Type in the quoted words to check them out)" << endl
                         << endl;
                    continue;
                }
                else if (input == "statue")
                {
                    cout << "This is definitely a statue of the Demon King. It is imposing and has a terrifying presence despite his laid back demeanor. The statue being 10 times larger than you doesn't help either. It's almost like it was made to scare people from coming closer... Well, it is in front of the gateway to the Underworld after all. There is nothing of importance to take though." << endl
                         << endl;
                    continue;
                }
                else if (input == "podium")
                {
                    cout << "You walk up to the podium facing the portal. There are writings like scriptures written on them. They all pertain to the Demon King. It becomes clear to you how much the denizens of the Underworld look up to and revere the Demon King. But that doesn't matter to us. We're here to defeat him for what he has done." << endl
                         << endl;
                    continue;
                }
                else if (input == "inventory")
                {
                    CheckInventory();
                    continue;
                }
                else
                {
                    cout << "What???" << endl
                         << endl;
                    continue;
                }
            }
            else if (CurrentArea == &templeOfEnvy)
            { // Temple of Envy_________________________
                input = GetInput();
                cout << endl;
                if (input == "forward")
                {
                    cout << "Of course! A setback like this shall not impede on our journey. There is another dimensional rift's glowing haze emitting behind the throne. There is our way forward!--Hm? From the other side of the portal, an enemy comes through. It's a Demon! This is Liala, a powerful Demon under the rule of her king. She doesn’t speak a word but she appears to have every intention of blocking your way. This is perfect! Now you get to warm up before fighting the Demon King. En garde!" << endl
                         << endl;
                    // first battle here
                    combat = CombatGame(currentWeapon);
                    recentCombat = true;
                    if (combat == true)
                    {
                        GameOver();
                        break;
                    }
                    TravelBuffer();
                    CurrentArea = &templeOfGluttony;
                }
                else if (input == "search")
                {
                    cout << "There appears to be the 'throne' and an 'insignia' worth searching. The 'decor' is also worth noting. You know what to do to get to them." << endl
                         << endl;
                    continue;
                }
                else if (input == "throne")
                {
                    cout << "Ascending up the stairs, you stand before a throne. Two of them, actually. You noticed the portal behind them that will surely be your method forward but you focus more on the throne set. Black thrones with silver linings. You wonder who the second one is for. His second in command? Well, it’s probably none of our business. But you are far more curious about the axe leaning on the second throne. You feel as though you can wield it easily. It may be a tad dull and vintage in comparison to the extravagance of this throne room but it should be far more suitable for you than that stick you've been calling a weapon. You decide to take it with you." << endl
                         << endl;
                    // weapon here
                    currentWeapon = PickUpWeapon(dull_axe);
                    continue;
                }
                else if (input == "insignia")
                {
                    cout << "On a portrait, there is an insignia. A Serpent for the sin of Envy. Envy being synonymous with jealousy. Humans are so weak. They are jealous of the power the Demon King holds. But who wouldn’t be, I suppose. He is a powerful higher-dimensional being capable of destruction that humans could only dream of doing. So it goes to show that they would be envious of such feats when they cannot even do so much as shift between dimensions. But… we’re different. Human though we may be, we have power like no other. That is why we are the only one capable of defeating the Demon King… As if the insignia itself heard our resolve, it looked as though it came to us and attached itself onto our soul. But the insignia is still on the portrait. A strange development Let’s go forward when we’re ready…" << endl
                         << endl;
                    PickUpInsignia(Serpent);
                    continue;
                }
                else if (input == "decor")
                {
                    cout << "The red carpets and dark tint give this place a sense of royalty. You feel as though dirtying this place will leave you with a bill you could never pay off on your own. You feel a tad bit envious knowing that someone is able to live in such luxury while you briefly recall your basic unrefined lifestyle of living in a shabby cabin back in the Human World." << endl
                         << endl;
                    continue;
                }
                else if (input == "inventory")
                {
                    CheckInventory();
                    continue;
                }
                else
                {
                    cout << "What???" << endl
                         << endl;
                    continue;
                }
            }

            else if (CurrentArea == &templeOfGluttony)
            { // Temple of Gluttony_________________
                if (recentCombat == true)
                {
                    input = GetInput();
                    recentCombat = false;
                }
                input = GetInput();
                cout << endl;
                if (input == "forward")
                {
                    cout << "This place has no more value in our eyes. Let’s carry on to the next location. Or so you would have liked... To your surprise, another Demon has entered the scene! This is Yosuke, another powerful soldier who follows the Demon King! And he doesn't look like he came here to eat. Just like the last Demon, he doesn't say a word to you. It seems we're in store for more combat. It almost saddens you to have to fight and risk ruining the food but here goes...!" << endl
                         << endl;
                    // second battle here
                    combat = CombatGame(currentWeapon);
                    recentCombat = true;
                    if (combat == true)
                    {
                        GameOver();
                        break;
                    }
                    TravelBuffer();
                    CurrentArea = &templeOfGreed;
                }
                else if (input == "search")
                {
                    cout << "Looking closely, you see an ‘insignia’ on the wall enclosed in a picture frame. There’s also a ‘book’ ominously left open on a table for you to peek into. Additionally, something that appears to be a ‘newspaper’ on the same table as well." << endl
                         << endl;
                    continue;
                }
                else if (input == "back")
                {
                    cout << "We cannot go back. We promised that to ourselves." << endl
                         << endl;
                    continue;
                }
                else if (input == "insignia")
                {
                    cout << "An insignia. This one is a Boar for the sin of Gluttony. Now you are disappointed. The sin of Gluttony yet there is no food in sight! You would’ve loved nothing more than this place to be a kitchen rather than a library. You surmise that this sin is being represented as a greed for knowledge rather than food. You couldn’t help but sigh in defeat. I suppose getting fed before our battle was not in the cards for us. However, now you are certain. The dimensional rifts are taking you through the Sin series. The Temple of Sins lead you through the Seven Deadly Sins as you make your way to the Demon King. It is unexpected since you were raring to fight immediately, but you are not worried in the slightest. The insignia whimsically flows from off the frame you're staring at and appears as though it attaches onto you. Hm, but it's still there. Perhaps an illusion you should ignore. Let's keep rolling." << endl
                         << endl;
                    PickUpInsignia(Boar);
                    continue;
                }
                else if (input == "book")
                {
                    cout << "You walk over to the table and skim through the book. It's about the Demon King and a few of his triumphant victories against threats to the Demon World. Other entities other than demons and humans exist. The Demon King is notorious for eliminating them and indirectly helping out humans even if that wasn't his intention. Hm… while reading, you also find a few pages talking about his abilities and weaponry. Dagmor… True Megidolaon… Excalibur… Void Space… Wow, even an ability that can mess with a person’s memories… Wait! Oh…" << endl
                         << endl;
                    continue;
                }
                else if (input == "newspaper")
                {
                    cout << "This is a collection of some of the entities the Demon King has defeated. A being known as Trihexa. Another being Lucifer, one of the previous Demon Kings before his rule. And even the evil dragon Ahkilleus who tried to destroy the human world and demon world alike. He is locked in the eternal imprisonment that is the Demon King’s Void Space. You continue to flip through the pages until you’ve had enough and slam the paper onto the table. Forget this! We’re here to fight the Demon King, not study him. Let’s hurry it up and get outta here!" << endl
                         << endl;
                    cout << "Hm, wait a moment. Slamming the papers back onto the desk shook the table hard enough for you to notice something leaning on the table fall. It's a sword! You feel your skin crawl realizing that a Demon would totally bring their sword with them in a library but the atmosphere only makes you feel even more on edge with it being so quiet in here. If this was a scary movie, a jumpscare was bound to happen at any moment. But that won't happen. What will happen is you taking this sword for yourself! It's perfect! This will certainly help you in combat." << endl
                         << endl;
                    // Weapon here
                    currentWeapon = PickUpWeapon(knights_sword);
                    continue;
                }
                else if (input == "inventory")
                {
                    CheckInventory();
                    continue;
                }
                else
                {
                    cout << "What???" << endl
                         << endl;
                    continue;
                }
            }

            else if (CurrentArea == &templeOfGreed)
            { // Temple of Greed_______________________
                if (recentCombat == true)
                {
                    input = GetInput();
                    recentCombat = false;
                }
                input = GetInput();
                cout << endl;
                if (input == "forward")
                {
                    cout << "Yeah, let’s not waste any more time here. The door to the next room acts as our portal." << endl
                         << endl;
                    TravelBuffer();
                    CurrentArea = &templeOfSloth;
                }
                else if (input == "search")
                {
                    cout << "‘Food’. Of course we see that. Can’t miss it. Oh, and I guess there’s an ‘insignia’ too." << endl
                         << endl;
                    continue;
                }
                else if (input == "back")
                {
                    cout << "We cannot go back. We promised that to ourselves." << endl
                         << endl;
                    continue;
                }
                else if (input == "food")
                {
                    cout << "There is freshly made food waiting for you, begging to be devoured. It smells and looks good. You hardly pay heed to the fact that it is food you are not used to and eat your fill. Yeah, now there’s absolutely no way the Demon King wins against us." << endl;
                    continue;
                }
                else if (input == "insignia")
                {
                    cout << "This Insignia is on the face of an empty plate. A fox design is plastered on the plate for the sin of Greed. You wonder about its significance. How does greed relate to the Demon King? Perhaps before he was not, but now is a different story. You recall the reason you are fighting the Demon King in the first place. His carnage has gone out of control. Attacking Humans without reason and harvesting their power to increase his own is something only a tyrant would do. As the strongest human--as the person entrusted by everyone to save them, you must stop him… The insignia appears to resonate with your resolve and meld into your soul. Or... so it seemed. It still remains on the plate..." << endl
                         << endl;
                    PickUpInsignia(Fox);
                    continue;
                }
                else if (input == "inventory")
                {
                    CheckInventory();
                    continue;
                }
                else
                {
                    cout << "What???" << endl
                         << endl;
                    continue;
                }
            }

            else if (CurrentArea == &templeOfSloth)
            { // Temple of Sloth_______________________
                input = GetInput();
                cout << endl;
                if (input == "forward")
                {
                    cout << "You shoot your eyes open and reach your hand out, burying all the fatigue away so that you may overcome it. Unlike the other areas, you have yet to spot a rift to bring you from one place to another. So be it, we will make one ourselves! From your outstretched hand, you create a rift in dimensions that will bring you to the next area and leave this place behind." << endl
                         << endl;
                    TravelBuffer();
                    CurrentArea = &templeOfPride;
                }
                else if (input == "search")
                {
                    cout << "There is nothing but the ‘haze’ and the ‘cloud’ beneath your feet. Ah, and the ‘insignia’ in the sky." << endl
                         << endl;
                    continue;
                }
                else if (input == "back")
                {
                    cout << "We cannot go back. We promised that to ourselves." << endl
                         << endl;
                    continue;
                }
                else if (input == "haze")
                {
                    cout << "Once you look into the haze in front of you created by the intense heat, you begin to see something through it. Illusions? Could it be that you’re becoming delusional? Perhaps. In the illusory haze you see the Demon King walking further away from you like a distant mirage. Perhaps this was meant to dispirit you but the only thing it does is make you want to go chase after him despite you knowing that it was just an illusion." << endl
                         << endl;
                    continue;
                }
                else if (input == "cloud")
                {
                    cout << "As you limp to go through the scorching haze, you find yourself staring down into the clouds beneath your feet. You are amazed that you can get the experience of walking along them. Staring into them for so long triggers you to see a vision within them. Or perhaps a memory. You peer into it and see the Demon King. Despite looking so human, you can tell that him and the others around him are not humans. But still, you can see in the memory that they act just like them. They look happy. If a demon can smile like that--no--if a demon can feel the same span of emotions that a human can, is there really much of a difference between the two? You wonder…" << endl
                         << endl;
                    continue;
                }
                else if (input == "insignia")
                {
                    cout << "The grizzly insignia for the sin of Sloth bears down on you from above like the rays from the sun. You are able to stare into it because of how gifted you are… but it sure is hot. You almost don’t realize its glow ingraining itself on your soul for you to take with you." << endl
                         << endl;
                    PickUpInsignia(Grizzly);
                    continue;
                }
                else if (input == "inventory")
                {
                    CheckInventory();
                    continue;
                }
                else
                {
                    cout << "What???" << endl
                         << endl;
                    continue;
                }
            }

            else if (CurrentArea == &templeOfPride)
            { // Temple of Pride_______________________
                input = GetInput();
                cout << endl;
                if (input == "forward")
                {
                    cout << "There is a tree before you beckoning you forth with another portal. The path forward is obvious this time. Let us commence--Wait a moment... No way...! Before you is not a Demon but a Heavenly Warlord! A Sage! He appears to be like the others though in the sense where he is like a zombified creature, unable to speak to you. But he still bars the way. If he is who you think he is, this battle will be difficult but if you cannot defeat him, you definitely will not be able to defeat the Demon King. Prepare yourself for your battle against the Sage!" << endl
                         << endl;
                    // third battle here
                    combat = CombatGame(currentWeapon);
                    recentCombat = true;
                    if (combat == true)
                    {
                        GameOver();
                        break;
                    }
                    TravelBuffer();
                    CurrentArea = &templeOfLust;
                }
                else if (input == "search")
                {
                    cout << "There is ‘ether’ floating in the wind. The ‘fruit’ on these trees also look fascinating. Don’t forget about the ‘insignia’ too." << endl
                         << endl;
                    continue;
                }
                else if (input == "back")
                {
                    cout << "We cannot go back. We promised that to ourselves." << endl
                         << endl;
                    continue;
                }
                else if (input == "ether")
                {
                    cout << "A flowing blue substance passes through the wind. In the Sage Realm, Ether is far more tangible but it is always present no matter what realm you are in. In fact, all beings have some form of ether within them. The entire makeup for demons and other entities are completely made of this spiritual matter called ether. That is why they disperse in blue particles upon their defeat. Humans have some too but the amount is far less in comparison to other entities. Perhaps that is the reason most of them are not as powerful. But humans like you who can use ether efficiently are quite fearsome." << endl
                         << endl;
                    continue;
                }
                else if (input == "insignia")
                {
                    cout << "Printed on the bark of the tree is the symbol of a lion for the sin of Pride. Perhaps this is the pride of the Demon King. This realm. His master whom he met here. You feel that there is a bond you could not hope to describe. Or at least there was. You question if that bond is still there. You are not sure how but you have a feeling that if the Sage knew of the Demon King’s current actions, he would be disappointed… The insignia appears to approve of you though. Perhaps this is all a sign for something to come. You stare at the insignia symbol on the bark for a moment longer but you are aware that it is with you rather than something exterior like this symbol on the tree..." << endl
                         << endl;
                    PickUpInsignia(Lion);
                    continue;
                }
                else if (input == "fruit")
                {
                    cout << "You recall bits of history belonging to the Demon King after picking a fruit from a tree. He was not always so powerful. The Sage Realm itself is actually where he met his master. After falling into this dimension due to his last defeat, he met a Sage who became his master. Part of his training involved eating these Sage Fruits. It’s almost refreshing to know that this Demon King fellow wasn’t always just some insanely strong monster… You throw the fruit on the ground though. No way you’re eating that. You heard they taste bad…" << endl
                         << endl;
                    cout << "Oh? You watch as the Sage Fruit rolls onto the ground and continues to the other side of the tree and down towards the hill. There, you see a sword struck into the ground, encircled by a small mystcial lake. In the middle is a sharp sword that feels like it's screaming your name. You immediately go to pick it up and sparks fly off the sword as you do. The power behind this weapon is unfathomable! You love it! So obviously, you're taking it with you." << endl
                         << endl;
                    // A weapon here
                    currentWeapon = PickUpWeapon(flaming_sword);
                    continue;
                }
                else if (input == "inventory")
                {
                    CheckInventory();
                    continue;
                }
                else
                {
                    cout << "What???" << endl
                         << endl;
                    continue;
                }
            }

            else if (CurrentArea == &templeOfLust)
            { // Temple of Lust_________________________
                if (recentCombat == true)
                {
                    input = GetInput();
                    recentCombat = false;
                }
                input = GetInput();
                cout << endl;
                if (input == "forward")
                {
                    cout << "This place is too drab for our liking. A moment longer here will surely freeze us solid. The portal seems to be behind that block of ice in the heart of the cocytus. Let’s go." << endl
                         << endl;
                    TravelBuffer();
                    CurrentArea = &templeOfWrath;
                }
                else if (input == "search")
                {
                    cout << "There is nothing here for us other than the ‘insignia.’ There are empty ‘cells’ of imprisonment if they catch your attention." << endl
                         << endl;
                    continue;
                }
                else if (input == "back")
                {
                    cout << "We cannot go back. We promised that to ourselves." << endl
                         << endl;
                    continue;
                }
                else if (input == "insignia")
                {
                    cout << "The goat sin of lust. Lust for battle would probably be an accurate way to describe the Demon King. But he never really had a bloodlust for killing. Even the most stubborn of enemies that went against him could be preserved in the Cocytus. Not that any of that matters to you. We’re going to win against the Demon King, so we won’t have to worry about visiting the Cocytus again. The insignia approves and appeared as though it crashed into you. Strange that you can still see it. An illusion? Doesn't matter, I suppose." << endl
                         << endl;
                    PickUpInsignia(Goat);
                    continue;
                }
                else if (input == "cells")
                {
                    cout << "Empty, cold, and lifeless. You have the ability to sense ether but you cannot even sense any of the remains that used to be here from previous inmates. Could it be that the Demon King took their ether composition while they were in imprisonment. If that is the case… that would mean he… Let’s not think about it right now…" << endl
                         << endl;
                    continue;
                }
                else if (input == "inventory")
                {
                    CheckInventory();
                    continue;
                }
                else
                {
                    cout << "What???" << endl
                         << endl;
                    continue;
                }
            }
            else if (CurrentArea == &templeOfWrath)
            { // Temple of Wrath_______________________
                input = GetInput();
                cout << endl;
                if (input == "forward")
                {
                    cout << "You can feel it. You are close to the end. A huge portal stares back at you at the center of the palace. We soon will reach the end and face the Demon King. You race forward." << endl
                         << endl;
                    // fourth battle here
                    combat = CombatGame(currentWeapon);
                    recentCombat = true;
                    if (combat == true)
                    {
                        GameOver();
                        break;
                    }
                    TravelBuffer();
                    CurrentArea = &templeOfVainglory;
                }
                else if (input == "search")
                {
                    cout << "There is an ‘Insignia’. Also, you cannot help but look up at the ‘sky’ with some kind of strange fondness." << endl
                         << endl;
                    continue;
                }
                else if (input == "back")
                {
                    cout << "We cannot go back. We promised that to ourselves." << endl
                         << endl;
                    continue;
                }
                else if (input == "insignia")
                {
                    cout << "The dragon insignia of wrath! The one that most closely correlates to the identity of the Demon King. It is printed onto this palace’s flag. Do not let the fondness of those around him such as other demons fool you. This Demon King is absolutely a force to be reckoned with! An army follows behind his footsteps and attacks at his command. No sane person would ever challenge him. Not before when he was kinder--and most certainly not now… The most powerful of the insignia recognizes your strength and etches itself onto your soul. You feel its power despite your confusion on the matter." << endl
                         << endl;
                    PickUpInsignia(Dragon);
                    continue;
                }
                else if (input == "sky")
                {
                    cout << "The sky is red here in the Underworld. It’s terrifying. Or at least it should be. But you feel at home… Probably just a fluke." << endl
                         << endl;
                    continue;
                }
                else if (input == "inventory")
                {
                    CheckInventory();
                    continue;
                }
                else
                {
                    cout << "What???" << endl
                         << endl;
                    continue;
                }
            }
            else if (CurrentArea == &templeOfVainglory)
            { // Temple of Vainglory_______________
                if (recentCombat == true)
                {
                    input = GetInput();
                    recentCombat = false;
                }
                input = GetInput();
                cout << endl;
                if (input == "forward")
                {
                    cout << "You reach your hand out into the void and attempt to break through it by forcibly making a rift from within the hopeless void. You hear whispers from the space itself. ‘Escape is impossible. Give up’ Show them that you refuse. Try again! Go ‘forward’. Maintain relentlessness." << endl
                         << endl;
                    string reply = GetInput();
                    cout << endl;
                    if (reply == "forward")
                    {
                        cout << "A tiny crack appears. The size of a dust mite. Even after all your tenacity and all the hard work we just put in, this was all we could do. ‘Do you see now? This is all you can do. The Demon King is far greater than you could ever hope to reach.’ The space whispers. Do not give up. One more time. 'Forward'." << endl
                             << endl;
                        string answer = GetInput();
                        cout << endl;
                        if (answer == "forward")
                        {
                            cout << "The Void Space has shattered!" << endl
                                 << endl;
                            CurrentArea = &sealedCite;
                        }
                        else
                        {
                            cout << "That is not the right answer..." << endl
                                 << endl;
                            continue;
                        }
                    }
                    else
                    {
                        cout << "That is not the right answer..." << endl
                             << endl;
                        continue;
                    }
                }
                else if (input == "search")
                {
                    cout << "There is nothing but darkness." << endl
                         << endl;
                    continue;
                }
                else if (input == "back")
                {
                    cout << "Even if we wanted to, we could not go back." << endl
                         << endl;
                    continue;
                }
                else
                {
                    cout << "Now is not the time to be funny. Type 'forward' and only 'forward'." << endl;
                    continue;
                }
            }
            else if (CurrentArea == &sealedCite)
            { // Sealed Cite_______________________________
                cout << "Go ahead and 'search'. It won't take long to find him." << endl
                     << endl;
                input = GetInput();
                cout << endl;
                if (input == "search")
                {
                    cout << "'Who are you?' You hear an unenthusiastic voice echo forth towards you. You turn to it and unmistakably find the Demon King. He looks like just another human but you are sure that you have found him here standing beside the dreary seal. He notices that you are human yet you were able to overcome the Void Space. An inescapable, infinite space... Nevermind that though. It is time to do what we came here for. Type 'fight' to engage in battle against the Demon King!" << endl
                         << endl;
                    string reply = GetInput();
                    cout << endl;
                    if (reply == "fight")
                    {
                        cout << "'I will be taking your energy. It will certainly be useful'. Without a word more, he takes out his trusty sword: Dagmor. The final battle ensues." << endl
                             << endl;
                        // Final Battle goes here.
                        combat = CombatGame(currentWeapon);
                        recentCombat = true;
                        if (combat == true)
                        {
                            GameOver();
                            break;
                        }
                        else
                        { ////////else if???????????????????????????????????
                            if (hasCompact == true)
                            {
                                PlayTrueEnding();
                                break;
                            }
                            else if (InsigniaCheck() == true)
                            {
                                InsigniaEnding();
                                break;
                            }
                            else
                            {
                                NormalEnding();
                                break;
                            }
                        }
                    }
                    else
                    {
                        cout << "Come on, don't chicken out now. Let's try this again." << endl
                             << endl;
                        continue;
                    }
                }
                else
                {
                    cout << "That's not it. 'Search'." << endl
                         << endl;
                    continue;
                }
            }
        }
        break;
    }
    // For non-gameover endings
    if (gameover == false)
    {
        cout << "The End" << endl;
        cout << "🎉 Congratulations! And thank you for playing the game! 🎉" << endl;
    }

    return 0;
}
