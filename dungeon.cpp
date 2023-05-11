#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>


using namespace std;

//  THINGS TO DO:
// - When you enter a new room and a space between things.
// - Add time between the responses to (not too long) ref: Sleep(0700);



int items(bool wand, bool eyeball, bool fish, bool spiderFriend, bool PitLantern)
{

if (wand == true)
{
return true;
}

if (eyeball)
{
return true;
}

if (fish == true)
{
return true;
}

if (PitLantern == true)
{
return true;
}

return false;
}

int getRandom()
{
    return (rand() % 4) + 1;
}

int guardFight(int health , int attack, int stamina, int enemyHealth, int enemyStamina, bool fbpads, bool wand, bool bat, bool sword, bool eyeball, bool fish, bool pitBlessing, bool xbow, bool spiderFriend, bool PitLantern)
{

srand(time(NULL));


std::cout << "\nThe Guard unsheathes his sword...\n\n";

bool playerTurn = true;
bool enemyTurn = false;

bool EyeballActive = false;

int playerEffect;
int enemyEffect;
int SPEffect;

string strat = "";
if (pitBlessing == false)
{
health = 100;
}
if (pitBlessing == true)
{
health = 130;
}
stamina = 25;

if (bat == true)
{
attack = 30;    
}

if (sword == true)
{
attack = 50;
}

if (xbow == true)
{
attack = 30;
}


enemyHealth = 200;
enemyStamina = 15;
bool enemyHealing = false;
bool enemyPoison = false;
bool spiderDistract = false;
int spiderTrap = 0;

int wandUses = 3;
int EyeUses = 3;
int pitUses = 1;
int SPuses = 1;
int poisonL = 3;


while (enemyHealth > 0)
{

while (playerTurn == true)
{
    
    if (health <= 0)
    {
        return 1;
    }

    std::cout << "\n-----------------------------------------------------------------------------------------\n";
    std::cout << "\n=== Health: " << health << " ===" << "\n=== Stamina: " << stamina << " ===\n \n";

if (items(wand, eyeball, fish, spiderFriend, PitLantern) == false)
{
std::cout << "What will you do? (attack [damages enemy] / rest [restores stamina and health + 10]): ";   
}
if (items(wand, eyeball, fish, spiderFriend, PitLantern) == true)
{
std::cout << "What will you do? (attack [damages enemy] / rest [restores stamina and health + 10] / items [Select one of your items in your inventory for use]): ";    
}

    std::cin >> strat;
    std::cout << "\n";

if (strat == "attack")
{

if (bat == true)
{
        if (stamina < 5)
        {
            std::cout << "\n\n### You need AT LEAST-- 5 Stamina -- to attack! ### \n\n";
            continue;
        }

        playerEffect = getRandom();
        enemyEffect = getRandom();
        
        if (playerEffect == 1)
        {
            std::cout << "\nYou swing your Bat!\n";
            std::cout << "You completely MISS!!\n\n";

        }

        if (playerEffect == 2)
        {
            int change = attack * .2;

            std::cout << "\nYou swing your Bat!\n";
            attack -= change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Giant Guard ~ but just barely! You do " << attack << " damage! \n\n";
            attack = 30;

        }
        
        if (playerEffect == 3)
        {
            std::cout << "\nYou swing your Bat!\n";
            enemyHealth -= attack;
            std::cout << "You hit the ~ Giant Guard ~ and it connects! You do " << attack << " damage!\n\n";
        }
        
        if (playerEffect == 4)
        {
            std::cout << "\nYou swing your Bat!\n";
            int change = attack * .2;
            attack += change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Giant Guard ~ and it's a solid hit! You do " << attack << " damage! \n\n";
            attack = 30;
        }

        if (enemyHealth < 0)
        {
            enemyHealth = 0;
        }

        std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";
        stamina -= 5;
        playerTurn = false;
        enemyTurn = true;
        strat = "";
}

if (sword == true)
{
            if (stamina < 10)
        {
            std::cout << "\n\n### You need AT LEAST-- 10 Stamina -- to attack! ### \n\n";
            continue;
        }

        playerEffect = getRandom();
        enemyEffect = getRandom();
        
        if (playerEffect == 1)
        {
            std::cout << "\nYou swing your Sword!\n";
            std::cout << "You completely MISS!!\n\n";

        }

        if (playerEffect == 2)
        {
            int change = attack * .2;

            std::cout << "\nYou swing your Sword!\n";
            attack -= change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Giant Guard ~ but just barely! You do " << attack << " damage! \n\n";
            attack = 50;

        }
        
        if (playerEffect == 3)
        {
            std::cout << "\nYou swing your Sword!\n";
            enemyHealth -= attack;
            std::cout << "You hit the ~ Giant Guard ~ and it connects! You do " << attack << " damage!\n\n";
        }
        
        if (playerEffect == 4)
        {
            std::cout << "\nYou swing your Sword!\n";
            int change = attack * .2;
            attack += change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Giant Guard ~ and it's a solid hit! You do " << attack << " damage! \n\n";
            attack = 50;
        }
        stamina -= 10;

        if (enemyHealth < 0)
        {
            enemyHealth = 0;
        }

        std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";

        playerTurn = false;
        enemyTurn = true;
        strat = "";
}

if (xbow == true)
{
            if (stamina < 10)
        {
            std::cout << "\n\n### You need AT LEAST-- 10 Stamina -- to attack! ### \n\n";
            continue;
        }

        playerEffect = getRandom();
        enemyEffect = getRandom();
        
        if (playerEffect == 1)
        {
            std::cout << "\nYou shoot your Crossbow!\n";
            std::cout << "You completely MISS!!\n\n";

        }

        if (playerEffect == 2)
        {
            int change = attack * .9;

            std::cout << "\nYou shoot your Crossbow!\n";
            attack -= change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Giant Guard ~ but the arrow skims his skin! You do " << attack << " damage! \n\n";
            attack = 30;

        }
        
        if (playerEffect == 3)
        {
            std::cout << "\nYou shoot your Crossbow!\n";
            enemyHealth -= attack;
            std::cout << "You hit the ~ Giant Guard ~ and it connects! You do " << attack << " damage!\n\n";
        }
        
        if (playerEffect == 4)
        {
            std::cout << "\nYou shoot you Crossbow!\n";
            int change = attack * 1.1;
            attack += change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Giant Guard ~ and it's a shot to the neck! You do " << attack << " damage! \n\n";
            attack = 30;
        }
        stamina -= 10;

        if (enemyHealth < 0)
        {
            enemyHealth = 0;
        }

        std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";

        playerTurn = false;
        enemyTurn = true;
        strat = "";
}
}

if (strat == "rest")
{
      if (pitBlessing == false)
    {
     if (health == 100 && stamina == 25)
    {
        std::cout << "\n### You don't need to rest. You feel fine. ###\n";
        continue;
    }        
    }

    if (pitBlessing == true)
    {
    if (health == 130 && stamina == 25)
    {
        std::cout << "\n### You don't need to rest. You feel fine. ###\n";
        continue;
    }   
    }

if (pitBlessing == false)
{
if (health < 100)
    {
        int h = 100 - health;

        if (h > 10)
        {
            std::cout << "\n Rested and restored +10 Health. ";
            health += 10;
        }

        if (h < 10)
        {
            std::cout << "\n Rested and restored +" << h << " Health.";
            health += h;
        }
    }    
}

if (pitBlessing == true)
{
if (health < 130)
    {
        int h = 130 - health;

        if (h > 10)
        {
            std::cout << "\n Rested and restored +10 Health. ";
            health += 10;
        }

        if (h < 10)
        {
            std::cout << "\n Rested and restored +" << h << " Health.";
            health += h;
        }
    }  
}
    

    if (stamina < 25)
    {
        int s = 25 - stamina;

        if (s > 10)
        {
            std::cout << "Rested and restored +10 Stamina.\n";
            stamina += 10;
        }

        if (s <= 10)
        {
            std::cout << "Rested and restored +" << s << " Stamina.\n";
            stamina += s;
        }
    }

    enemyTurn = true;
    playerTurn = false;
    strat = "";
    }

if (strat == "mod")
    {
        enemyHealth = 0;
        enemyTurn = true;
        playerTurn = false;
    }

if (strat == "items" && items(wand, eyeball, fish, spiderFriend, PitLantern) == true)
{
std::cout << "\n=== Items (Select which one) ===\n\n";

if (wand == true)
{
    std::cout << "    Wand (+50 Health + Max Stamina)   \n";

}
        
if (eyeball == true)
{
    std::cout << "    Eyeball (Reflects Damage)   \n";
}
        
if (fish == true)
{
    std::cout << "    Fish (Feed Your Enemy?)   \n";
}

if (PitLantern == true)
{
std::cout << "   Pit Lantern (Type Pit to Select)   \n";
}

if (spiderFriend == true)
{
  std::cout << "   Spider Friend! (Type SP to select)   \n";  
}


std::cout << "\nSelect (cap sensitive): ";
strat = "";
std::cin >> strat;

if (strat == "Wand")
{
        if (wand == true)
        {
        strat = "";
        if (health == 100 && stamina == 25)
        {
            std::cout << "\n### You don't need to use the Wand. You feel fine. ###\n";
            continue;
        }
        std::cout << "\nYou wave the wand in the air. Sparks come out...\n\n";

        if (health < 100 && stamina < 25)
        {

            int h = 100 - health;

        if (h > 50)
        {
            std::cout << "\n=== The Wand heals 50 Health";
            health += 50;
        }
        if (h <= 50)
        {
            std::cout << "\n=== The Wand heals " << h << " Health";
            health += h;
        }

            stamina = 25;

            std::cout << " and maxes your Stamina ===\n\n";
        }

        if (health == 100 && stamina < 25)
        {
            stamina = 25;
            std::cout << "\n=== The Wand maxes your Stamina ===\n\n";
        }
        if (health < 100 && stamina == 25)
        {
             int h = 100 - health;

               if (h <= 50)
               {
                std::cout << "\n=== The Wand heals " << h << " Health";
                health += h;
               }

        }

        wandUses -= 1;

        if (wandUses == 1)
        {
            std::cout << "The wand fades from it's dark brown to a black color. If you use it again it WILL break... ===\n\n";
        }

        if (wandUses == 0)
        {
            std::cout << "The wand spazes out of your hand and explodes into a cloud of dust...\n\n";
            std::cout << "=== You LOSE the Wand ===\n\n";
            wand = false;
        }

        playerTurn = false;
        enemyTurn = true;
        
} else if (wand == false)
{
    std::cout << "\n### You do not own the Wand ###\n\n";
}

}

if (strat == "Eyeball")
{

if (EyeUses == 0)
{
    std::cout << "\n### The Eyeball is dried out and unuseable for the round! ###\n";
    continue;
}
    strat = "";

    if (enemyHealing == false)
{
    std::cout << "\n=== You rub the Eyeball on you. The Slime reaks! ===\n";
    EyeballActive = true;
}

 if (enemyHealing == true)
{
    std::cout <<"\n### It would be a waste to use the Eyeball now! ###\n";
    continue;
}

EyeUses -= 1;

if (EyeUses == 1)
{
    std::cout << "\n=== The Eyeball is now feeling really dry. Your next use is your last for the round ===\n";
}



}

if (strat == "Fish")
{
    std::cout << "\n=== The Guard doesn't seem to react to the Fish ===\n";
    continue;
}
        
if (strat == "Pit")
{

if (pitUses == 0)
{
    std::cout << "\n## The Lantern seems dim. Try again next round ##\n";
    continue;
}

if (pitUses == 1)
{
    std::cout << "\n=== The Lantern Glows Brightly ===\n";
    int LEffect = getRandom();

    if (LEffect == 1)
{
    std::cout << "== The Lantern fires a beam of light! ==\n";
    enemyHealth -= 5;   
    std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";
    pitUses -= 1;

}

if (LEffect == 2)
{
    std::cout << "== The Lantern shines and fires powerful beam of light! Damaging the boss! ==";
    enemyHealth -= 15;
    std::cout << "\n=== Enemy Health: " << enemyHealth << " ===\n";   
    pitUses -= 1;
}

if (LEffect == 3)
{
    std::cout << "== The Lantern shines and fires powerful beam of light! Damaging the boss! ==";
    enemyHealth -= 15;
    std::cout << "\n=== Enemy Health: " << enemyHealth << " ===\n\n";   
    pitUses -= 1;
}

if (LEffect == 4)
{
    std::cout << "== The Lantern rattles and shakes and rattles ==\n";
    std::cout << "== The orange flame turns black and a white beam shoots out doing INCREDIBLE DAMAGE! ==\n";
    enemyHealth -= 40;
    std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";
    pitUses -= 1;

}
}

}    

if (strat == "SP")
{

if (SPuses == 0)
{
    std::cout << "\n## Your Spider Friend seems out of breath. Try again next round ##\n";
    continue;
}

if (SPuses == 1)
{
    std::cout << "\n=== Your Spider Buddy crouches low ===\n";
    SPEffect = getRandom();

if (SPEffect == 1)
{
    std::cout << "== He lunges forward and bites the Guard! ==\n";
    enemyHealth -= 10;   
    std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";
    SPuses -= 1;

}

if (SPEffect == 2)
{
    std::cout << "== The Spider shoots a hot ball of posion out of it's abdomen and posisens the Boss! ==";
    poisonL = 3;
    enemyPoison = true;  
    SPuses -= 1;
}

if (SPEffect == 3)
{
    std::cout << "== The Spider threads web to distract the Boss ==";
    spiderDistract = true;   
    SPuses -= 1;
}

if (SPEffect == 4)
{
    std::cout << "== The Spider begins threading web meticulously ==\n";
    std::cout << "== The Spider is setting a trap! ==\n";
    spiderTrap += 1;    
    SPuses -= 1;
}

if (spiderTrap == 3)
{
    std::cout << "== The trap the Spider was setting up collapses! ==\n";
    std::cout << "== It does HUGE DAMAGE! ==";
    enemyHealth -= 100;
    std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";
    SPuses -= 1;
    spiderTrap = 0;
}

        }
    }
}

while (enemyTurn == true)
    {
      
if (enemyTurn == true)
{
    if (enemyHealth <= 0)
    {
        std::cout << "\n The Guard stumbles.\n";
        std::cout << "You go in for the finishing blow but it isn't neccessary as he falls over and turns to dust as he lands...\n";

        std::cout << "\n\n === The Giant Guard has Fallen ===\n\n";
            return 0;
        } 

    int stamCost = 5;
    pitUses += 1;
    SPuses += 1;

    if (pitUses > 1)
    {
        pitUses = 1;
    }

    if (SPuses > 1)
    {
        SPuses = 1;
    }

    if (enemyStamina < stamCost)
        {
            enemyHealing = true;
        }

    if (enemyStamina < 0)
        {
            enemyStamina = 0;
        }

    if (enemyStamina == 15)
        {
            enemyHealing = false;
        }

    if (enemyHealing)
        {
            enemyStamina += 5;

            if (enemyStamina > 15)
            {
                enemyStamina = 15;
            }

            std::cout << "~\n The Guard's eyeholes turn from white to black as he stands limp... \n~";
            std::cout << "~ He seems to be taking a break and will begin attacking once he's done resting... ~\n\n";

            std::cout << "~ Enemy Stamina: +" << enemyStamina << " ~\n\n";
            enemyTurn = false;
            playerTurn = true;
            break;
        }

    if (spiderDistract == true)
    {
        std::cout << "\n~ The Guard is preoccupied with taking cobweb off his face ~\n";
        std::cout << "\n~ He does not attack! ~\n";

        playerTurn = true;
        enemyTurn = false;
        spiderDistract = false;
        break;
    }

    if (enemyHealing == false && enemyEffect <= 2 && enemyStamina >= stamCost)
    {
    
    if (enemyPoison == true)
    {
        std::cout << "\n~ The Guard winces at the pain of the poison (-5 HP)~\n";
        enemyHealth -= 5;
        poisonL -= 1;
    }

    if (poisonL == 0)
    {
        std::cout << "== The Poison wears off ==\n";
    }


    if (EyeballActive == true)
    {
        std::cout << "\n~ The Guard slashes his sword and hits you!! ~";
        enemyStamina -= stamCost;

    if (fbpads == false)
    {
        health -= 20;
        std::cout << "(-  20 Health) ~\n";          
    }

    if (fbpads == true)
    {
        health -= 14;
        std::cout << "(-  14 Health) ~\n";
        std::cout <<"=== The Football Pads protect you a little! ===\n\n";
    }

        enemyHealth -=  40;
        
        enemyTurn = false;
        playerTurn = true;

        std::cout << "\n At the same instance his arm erupts in blood!\n";
        std::cout << "It hurt but not as much as it would have...\n";
        std::cout << "\n=== Enemy Health: " << enemyHealth << " ===\n\n";
        std::cout << "\n=== The Slime begins drying and no longer reflects damage! ===\n";

        EyeballActive = false;
        break;
    } 
    
    else if (EyeballActive == false)
    {
        std::cout << "\n~ The Guard slashes his sword and hits you!! ";
        enemyStamina -= stamCost;

    if (fbpads == false)
    {   
        health -= 40;
        std::cout << "(- 40 Health) ~\n\n";
    }
    if (fbpads == true)
    {
        health -= 33;
        std::cout << "(-  33 Health) ~\n";
        std::cout <<"=== The Football Pads protect you a little! ===\n\n";
            // 30% damage reduction
    }
            enemyHealing = false;
            enemyTurn = false;
            playerTurn = true;
            std::cout << "~ Enemy Stamina " << enemyStamina << " ~\n";
         }
    
    EyeballActive = false;
    }

    if (enemyHealing == false && enemyEffect == 3 && enemyStamina >= stamCost)
    {
    
    if (enemyPoison == true)
    {
        std::cout << "\n~ The Guard winces at the pain of the poison (-5 HP) ~\n";
        enemyHealth -= 5;
        poisonL -= 1;
    }

    if (poisonL == 0)
    {
        std::cout << "== The Poison wears off ==\n";
    }

        std::cout << "\n~ The Guard slashes his sword at you but he misses! ~\n";
        enemyStamina -= stamCost;

    if (EyeballActive == true)
    {
        std::cout << "\n=== The Slime begins drying and no longer reflects damage! ===\n";
    }
           enemyHealing = false;
           enemyTurn = false;
           playerTurn = true;
        std::cout << "\n~ Enemy Stamina " << enemyStamina << " ~\n\n";
    
        EyeballActive = false;
    }

    if (enemyHealing == false && enemyEffect == 4 && enemyStamina >= stamCost)
    {

    if (enemyPoison == true)
    {
        std::cout << "\n~ The Guard winces at the pain of the poison (-5 HP) ~\n";
        enemyHealth -= 5;
        poisonL -= 1;
    }

    if (poisonL == 0)
    {
        std::cout << "== The Poison wears off ==\n";
    }

        if (spiderDistract == true)
    {
        std::cout << "\n~ The Guard is preoccupied with taking cobweb off his face ~\n";
        std::cout << "\n~ He does not attack! ~\n";

        spiderDistract =  false;
        playerTurn = true;
        enemyTurn = false;
    }

    if (EyeballActive == true)
    {
        std::cout << "\n~ The Guard slashes his sword and hits you!! ~";
        enemyStamina -= stamCost;

    if (fbpads == false)
    {
        health -= 25;
        std::cout << "(-  25 Health) ~\n";          
    }

    if (fbpads == true)
    {
        health -= 17;
        std::cout << "(-  17 Health) ~\n";
        std::cout <<"=== The Football Pads protect you a little! ===\n\n";
    }

        enemyHealth -=  50;
        
        enemyTurn = false;
        playerTurn = true;

        std::cout << "\n At the same instance his arm erupts in blood!\n";
        std::cout << "It hurt but not as much as it would have...\n";
        std::cout << "\n=== Enemy Health: " << enemyHealth << " ===\n\n";
        std::cout << "\n=== The Slime begins drying and no longer reflects damage! ===\n";

    EyeballActive = false; 
        break;
    } 
    
    else if (EyeballActive == false)
    {
        std::cout << "\n~ The Guard slashes his sword and hits you!! ";
        enemyStamina -= stamCost;

    if (fbpads == false)
    {   
        health -= 40;
        std::cout << "(- 40 Health) ~\n\n";
    }
    if (fbpads == true)
    {
        health -= 33;
        std::cout << "(-  33 Health) ~\n";
        std::cout <<"=== The Football Pads protect you a little! ===\n\n";
            // 30% damage reduction
    }
        enemyHealing = false;
        enemyTurn = false;
        playerTurn = true;
        std::cout << "~ Enemy Stamina " << enemyStamina << " ~\n";
    
       
}
    
    else if (EyeballActive == false)
    {
        std::cout << "\n~ The Guard draws his sword back super fast and slashes you! It's a critical hit! ";
        enemyStamina -= stamCost;

        if (fbpads == false)
            {   
            std::cout << "(- 50 Health) ~\n";
            health -= 50;
            }
            if (fbpads == true)
            {
                health -= 36;
                std::cout << "(- 36 Health) ~\n";
                std::cout <<"\n=== The Football Pads protect you a little! ===\n";
                // 30% damage reduction
            }

            std::cout << "\n~ Enemy Stamina " << enemyStamina << " ~\n\n";
            std::cout << "\n-----------------------------------------------------------------------------------------\n";

            enemyHealing = false;
           enemyTurn = false;
           playerTurn = true;
    }   

 
    } // end of turn

                }

            }
    
        }   

    }
}

int dragonFight(int health , int attack, int stamina, int enemyHealth, int enemyStamina, bool fbpads, bool wand, bool bat, bool sword, bool eyeball, bool fish, bool pitBlessing, bool xbow, bool spiderFriend, bool PitLantern, bool GuardSword)
{

std::cout << "\nYou enter and a huge dragon lays nested in a pile of bone, ash, and twigs.";
std::cout << "\n=== The dragon wakes to your presence! ===\n";

system("CLS");

std::cout << "You prepare for the battle of your life!!\n";

bool playerTurn = true;
bool enemyTurn = false;

bool EyeballActive = false;

int playerEffect;
int enemyEffect;
int SPEffect;

string strat = "";
if (pitBlessing == false)
{
health = 100;
}
if (pitBlessing == true)
{
health = 130;
}
stamina = 25;

if (bat == true)
{
attack = 30;    
}

if (sword == true)
{
attack = 50;
}

if (xbow == true)
{
attack = 30;
}

if (GuardSword == true)
{
    attack = 60;
}

enemyHealth = 200;
enemyStamina = 15;
bool enemyHealing = false;
bool enemyPoison = false;
bool spiderDistract = false;
int spiderTrap = 0;

int wandUses = 3;
int EyeUses = 3;
int pitUses = 1;
int SPuses = 1;
int poisonL = 3;


while (enemyHealth > 0)
{

while (playerTurn == true)
{
    
    if (health <= 0)
    {
        return 1;
    }

    std::cout << "\n-----------------------------------------------------------------------------------------\n";
    std::cout << "\n=== Health: " << health << " ===" << "\n=== Stamina: " << stamina << " ===\n \n";

if (items(wand, eyeball, fish, spiderFriend, PitLantern) == false)
{
std::cout << "What will you do? (attack [damages enemy] / rest [restores stamina and health + 10]): ";   
}
if (items(wand, eyeball, fish, spiderFriend, PitLantern) == true)
{
std::cout << "What will you do? (attack [damages enemy] / rest [restores stamina and health + 10] / items [Select one of your items in your inventory for use]): ";    
}

    std::cin >> strat;
    std::cout << "\n";

if (strat == "attack")
{

if (bat == true)
{
        if (stamina < 5)
        {
            std::cout << "\n\n### You need AT LEAST-- 5 Stamina -- to attack! ### \n\n";
            continue;
        }

        playerEffect = getRandom();
        enemyEffect = getRandom();
        
        if (playerEffect == 1)
        {
            std::cout << "\nYou swing your Bat!\n";
            std::cout << "You completely MISS!!\n\n";

        }

        if (playerEffect == 2)
        {
            int change = attack * .2;

            std::cout << "\nYou swing your Bat!\n";
            attack -= change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Dragon ~ but just barely! You do " << attack << " damage! \n\n";
            attack = 30;

        }
        
        if (playerEffect == 3)
        {
            std::cout << "\nYou swing your Bat!\n";
            enemyHealth -= attack;
            std::cout << "You hit the ~ Dragon ~ and it connects! You do " << attack << " damage!\n\n";
        }
        
        if (playerEffect == 4)
        {
            std::cout << "\nYou swing your Bat!\n";
            int change = attack * .2;
            attack += change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Dragon ~ and it's a solid hit! You do " << attack << " damage! \n\n";
            attack = 30;
        }

        if (enemyHealth < 0)
        {
            enemyHealth = 0;
        }

        std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";
        stamina -= 5;
        playerTurn = false;
        enemyTurn = true;
        strat = "";
}

if (sword == true)
{
if (stamina < 10)
{
    std::cout << "\n\n### You need AT LEAST-- 10 Stamina -- to attack! ### \n\n";
    continue;
}

    playerEffect = getRandom();
    enemyEffect = getRandom();
        
if (playerEffect == 1)
{
    std::cout << "\nYou swing your Sword!\n";
    std::cout << "You completely MISS!!\n\n";
}

if (playerEffect == 2)
{
    int change = attack * .2;

    std::cout << "\nYou swing your Sword!\n";
    attack -= change;
    enemyHealth -= attack;
    std::cout << "You hit the ~ Giant Guard ~ but just barely! You do " << attack << " damage! \n\n";
    attack = 50;

}
        
if (playerEffect == 3)
{
    std::cout << "\nYou swing your Sword!\n";
    enemyHealth -= attack;
    std::cout << "You hit the ~ Giant Guard ~ and it connects! You do " << attack << " damage!\n\n";
}
        
if (playerEffect == 4)
{
    std::cout << "\nYou swing your Sword!\n";
    int change = attack * .2;
    attack += change;
    enemyHealth -= attack;
    std::cout << "You hit the ~ Giant Guard ~ and it's a solid hit! You do " << attack << " damage! \n\n";
    attack = 50;
}
stamina -= 10;

if (enemyHealth < 0)
{
    enemyHealth = 0;
}

    std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";

    playerTurn = false;
    enemyTurn = true;
    strat = "";
}

if (xbow == true)
{
            if (stamina < 10)
        {
            std::cout << "\n\n### You need AT LEAST-- 10 Stamina -- to attack! ### \n\n";
            continue;
        }

        playerEffect = getRandom();
        enemyEffect = getRandom();
        
        if (playerEffect == 1)
        {
            std::cout << "\nYou shoot your Crossbow!\n";
            std::cout << "You completely MISS!!\n\n";

        }

        if (playerEffect == 2)
        {
            int change = attack * .9;

            std::cout << "\nYou shoot your Crossbow!\n";
            attack -= change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Dragon ~ but the arrow skims his scales! You do " << attack << " damage! \n\n";
            attack = 30;

        }
        
        if (playerEffect == 3)
        {
            std::cout << "\nYou shoot your Crossbow!\n";
            enemyHealth -= attack;
            std::cout << "You hit the ~ Dragon ~ and it connects! You do " << attack << " damage!\n\n";
        }
        
        if (playerEffect == 4)
        {
            std::cout << "\nYou shoot you Crossbow!\n";
            int change = attack * 1.1;
            attack += change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Dragon ~ and it's a shot to the neck! You do " << attack << " damage! \n\n";
            attack = 30;
        }
        stamina -= 10;

        if (enemyHealth < 0)
        {
            enemyHealth = 0;
        }

        std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";

        playerTurn = false;
        enemyTurn = true;
        strat = "";
}

if (GuardSword == true)
{
if (stamina < 10)
{
    std::cout << "\n\n### You need AT LEAST-- 10 Stamina -- to attack! ### \n\n";
    continue;
}

    playerEffect = getRandom();
    enemyEffect = getRandom();
        
if (playerEffect == 1)
{
    std::cout << "\nYou swing your Sword!\n";
    std::cout << "You completely MISS!!\n\n";
}

if (playerEffect == 2)
{
    int change = attack * .2;

    std::cout << "\nYou swing your Sword!\n";
    attack -= change;
    enemyHealth -= attack;
    std::cout << "You hit the ~ Dragon ~ but just barely! You do " << attack << " damage! \n\n";
    attack = 60;

}
        
if (playerEffect == 3)
{
    std::cout << "\nYou swing your Sword!\n";
    enemyHealth -= attack;
    std::cout << "You hit the ~ Dragon ~ and it connects! You do " << attack << " damage!\n\n";
}
        
if (playerEffect == 4)
{
    std::cout << "\nYou swing your Sword!\n";
    int change = attack * .2;
    attack += change;
    enemyHealth -= attack;
    std::cout << "You hit the ~ Dragon ~ and it's a solid hit! You do " << attack << " damage! \n\n";
    attack = 60;
}
stamina -= 10;

if (enemyHealth < 0)
{
    enemyHealth = 0;
}

    std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";

    playerTurn = false;
    enemyTurn = true;
    strat = "";
}
}

if (strat == "rest")
{
      if (pitBlessing == false)
    {
     if (health == 100 && stamina == 25)
    {
        std::cout << "\n### You don't need to rest. You feel fine. ###\n";
        continue;
    }        
    }

    if (pitBlessing == true)
    {
    if (health == 130 && stamina == 25)
    {
        std::cout << "\n### You don't need to rest. You feel fine. ###\n";
        continue;
    }   
    }

if (pitBlessing == false)
{
if (health < 100)
    {
        int h = 100 - health;

        if (h > 10)
        {
            std::cout << "\n Rested and restored +10 Health. ";
            health += 10;
        }

        if (h < 10)
        {
            std::cout << "\n Rested and restored +" << h << " Health.";
            health += h;
        }
    }    
}

if (pitBlessing == true)
{
if (health < 130)
    {
        int h = 130 - health;

        if (h > 10)
        {
            std::cout << "\n Rested and restored +10 Health. ";
            health += 10;
        }

        if (h < 10)
        {
            std::cout << "\n Rested and restored +" << h << " Health.";
            health += h;
        }
    }  
}
    
    if (stamina < 25)
    {
        int s = 25 - stamina;

        if (s > 10)
        {
            std::cout << "Rested and restored +10 Stamina.\n";
            stamina += 10;
        }

        if (s <= 10)
        {
            std::cout << "Rested and restored +" << s << " Stamina.\n";
            stamina += s;
        }
    }

    enemyTurn = true;
    playerTurn = false;
    strat = "";
    }

if (strat == "mod")
    {
        enemyHealth = 0;
        enemyTurn = true;
        playerTurn = false;
    }

if (strat == "items" && items(wand, eyeball, fish, spiderFriend, PitLantern) == true)
{
std::cout << "\n=== Items (Select which one) ===\n\n";

if (wand == true)
{
    std::cout << "    Wand (+50 Health + Max Stamina)   \n";

}
        
if (eyeball == true)
{
    std::cout << "    Eyeball (Reflects Damage)   \n";
}
        
if (fish == true)
{
    std::cout << "    Fish (Feed Your Enemy?)   \n";
}

if (PitLantern == true)
{
std::cout << "   Pit Lantern (Type Pit to Select)   \n";
}

if (spiderFriend == true)
{
  std::cout << "   Spider Friend! (Type SP to select)   \n";  
}


std::cout << "\nSelect (cap sensitive): ";
strat = "";
std::cin >> strat;

if (strat == "Wand")
{
        if (wand == true)
        {
        strat = "";
        if (health == 100 && stamina == 25)
        {
            std::cout << "\n### You don't need to use the Wand. You feel fine. ###\n";
            continue;
        }
        std::cout << "\nYou wave the wand in the air. Sparks come out...\n\n";

        if (health < 100 && stamina < 25)
        {

            int h = 100 - health;

        if (h > 50)
        {
            std::cout << "\n=== The Wand heals 50 Health";
            health += 50;
        }
        if (h <= 50)
        {
            std::cout << "\n=== The Wand heals " << h << " Health";
            health += h;
        }

            stamina = 25;

            std::cout << " and maxes your Stamina ===\n\n";
        }

        if (health == 100 && stamina < 25)
        {
            stamina = 25;
            std::cout << "\n=== The Wand maxes your Stamina ===\n\n";
        }
        if (health < 100 && stamina == 25)
        {
             int h = 100 - health;

               if (h <= 50)
               {
                std::cout << "\n=== The Wand heals " << h << " Health";
                health += h;
               }

        }

        wandUses -= 1;

        if (wandUses == 1)
        {
            std::cout << "The wand fades from it's dark brown to a black color. If you use it again it WILL break... ===\n\n";
        }

        if (wandUses == 0)
        {
            std::cout << "The wand spazes out of your hand and explodes into a cloud of dust...\n\n";
            std::cout << "=== You LOSE the Wand ===\n\n";
            wand = false;
        }

        playerTurn = false;
        enemyTurn = true;
        
} else if (wand == false)
{
    std::cout << "\n### You do not own the Wand ###\n\n";
}

}

if (strat == "Eyeball")
{

if (EyeUses == 0)
{
    std::cout << "\n### The Eyeball is dried out and unuseable for the round! ###\n";
    continue;
}
    strat = "";

    if (enemyHealing == false)
{
    std::cout << "\n=== You rub the Eyeball on you. The Slime reaks! ===\n";
    EyeballActive = true;
}

 if (enemyHealing == true)
{
    std::cout <<"\n### It would be a waste to use the Eyeball now! ###\n";
    continue;
}

EyeUses -= 1;

if (EyeUses == 1)
{
    std::cout << "\n=== The Eyeball is now feeling really dry. Your next use is your last for the round ===\n";
}



}

if (strat == "Fish")
{
    std::cout << "\n=== The Dragon takes your fish and eats it! He GAINS HEALTH IDIOT===\n";
    enemyHealth += 1;
    continue;
}
        
if (strat == "Pit")
{

if (pitUses == 0)
{
    std::cout << "\n## The Lantern seems dim. Try again next round ##\n";
    continue;
}

if (pitUses == 1)
{
    std::cout << "\n=== The Lantern Glows Brightly ===\n";
    int LEffect = getRandom();

    if (LEffect == 1)
{
    std::cout << "== The Lantern fires a beam of light! ==\n";
    enemyHealth -= 5;   
    std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";
    pitUses -= 1;

}

if (LEffect == 2)
{
    std::cout << "== The Lantern shines and fires powerful beam of light! Damaging the boss! ==";
    enemyHealth -= 15;
    std::cout << "\n=== Enemy Health: " << enemyHealth << " ===\n";   
    pitUses -= 1;
}

if (LEffect == 3)
{
    std::cout << "== The Lantern shines and fires powerful beam of light! Damaging the boss! ==";
    enemyHealth -= 15;
    std::cout << "\n=== Enemy Health: " << enemyHealth << " ===\n\n";   
    pitUses -= 1;
}

if (LEffect == 4)
{
    std::cout << "== The Lantern rattles and shakes and rattles ==\n";
    std::cout << "== The orange flame turns black and a white beam shoots out doing INCREDIBLE DAMAGE! ==\n";
    enemyHealth -= 40;
    std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";
    pitUses -= 1;

}
}

}    

if (strat == "SP")
{

if (SPuses == 0)
{
    std::cout << "\n## Your Spider Friend seems out of breath. Try again next round ##\n";
    continue;
}

if (SPuses == 1)
{
    std::cout << "\n=== Your Spider Buddy crouches low ===\n";
    SPEffect = getRandom();

if (SPEffect == 1)
{
    std::cout << "== He lunges forward and bites the Guard! ==\n";
    enemyHealth -= 10;   
    std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";
    SPuses -= 1;

}

if (SPEffect == 2)
{
    std::cout << "== The Spider shoots a hot ball of posion out of it's abdomen and posisens the Boss! ==";
    poisonL = 3;
    enemyPoison = true;  
    SPuses -= 1;
}

if (SPEffect == 3)
{
    std::cout << "== The Spider threads web to distract the Boss ==";
    spiderDistract = true;   
    SPuses -= 1;
}

if (SPEffect == 4)
{
    std::cout << "== The Spider begins threading web meticulously ==\n";
    std::cout << "== The Spider is setting a trap! ==\n";
    spiderTrap += 1;    
    SPuses -= 1;
}

if (spiderTrap == 3)
{
    std::cout << "== The trap the Spider was setting up collapses! ==\n";
    std::cout << "== It does HUGE DAMAGE! ==";
    enemyHealth -= 100;
    std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";
    SPuses -= 1;
    spiderTrap = 0;
}

        }
    }
}

while (enemyTurn == true)
    {
      
if (enemyTurn == true)
{
if (enemyHealth <= 0)
{
    std::cout << "\n The Dragon stops.\n";
    std::cout << "The Dragons scales cracks before it finally puffs into a cloud of purple smoke\n";

    std::cout << "\n\n === You ESCAPED THE DUNGEON ===\n\n";
    return 0;
} 

    int stamCost = 5;
    pitUses += 1;
    SPuses += 1;

    if (pitUses > 1)
    {
        pitUses = 1;
    }

    if (SPuses > 1)
    {
        SPuses = 1;
    }

    if (enemyStamina < stamCost)
        {
            enemyHealing = true;
        }

    if (enemyStamina < 0)
        {
            enemyStamina = 0;
        }

    if (enemyStamina == 15)
        {
            enemyHealing = false;
        }

    if (enemyHealing)
        {
            enemyStamina += 5;

            if (enemyStamina > 15)
            {
                enemyStamina = 15;
            }

            std::cout << "~\n The Dragon stands still to catch its breath... \n~";
            std::cout << "~ It seems to be taking a break and will begin attacking once he's done resting... ~\n\n";

            std::cout << "~ Enemy Stamina: +" << enemyStamina << " ~\n\n";
            enemyTurn = false;
            playerTurn = true;
            break;
        }

    if (spiderDistract == true)
    {
        std::cout << "\n~ The Dragon is preoccupied with taking cobweb off its beak~\n";
        std::cout << "\n~ It does not attack! ~\n";

        playerTurn = true;
        enemyTurn = false;
        spiderDistract = false;
        break;
    }

    if (enemyHealing == false && enemyEffect <= 2 && enemyStamina >= stamCost)
    {
    
    if (enemyPoison == true)
    {
        std::cout << "\n~ The Dragon winces at the pain of the poison (-5 HP)~\n";
        enemyHealth -= 5;
        poisonL -= 1;
    }

    if (poisonL == 0)
    {
        std::cout << "== The Poison wears off ==\n";
    }


    if (EyeballActive == true)
    {
        std::cout << "\n~ The Dragon slashes his claws!! ~";
        enemyStamina -= stamCost;

    if (fbpads == false)
    {
        health -= 15;
        std::cout << "(-  15 Health) ~\n";          
    }

    if (fbpads == true)
    {
        health -= 10;
        std::cout << "(-  10 Health) ~\n";
        std::cout <<"=== The Football Pads protect you a little! ===\n\n";
    }

        enemyHealth -=  30;
        
        enemyTurn = false;
        playerTurn = true;

        std::cout << "\n At the same instance its arm erupts in blood!\n";
        std::cout << "It hurt but not as much as it would have...\n";
        std::cout << "\n=== Enemy Health: " << enemyHealth << " ===\n\n";
        std::cout << "\n=== The Slime begins drying and no longer reflects damage! ===\n";

        EyeballActive = false;
        break;
    } 
    
    else if (EyeballActive == false)
    {
        std::cout << "\n~ The Dragon slashes its claws at you!! ";
        enemyStamina -= stamCost;

    if (fbpads == false)
    {   
        health -= 30;
        std::cout << "(- 30 Health) ~\n\n";
    }
    if (fbpads == true)
    {
        health -= 21;
        std::cout << "(-  21 Health) ~\n";
        std::cout <<"=== The Football Pads protect you a little! ===\n\n";
            // 30% damage reduction
    }
            enemyHealing = false;
            enemyTurn = false;
            playerTurn = true;
            std::cout << "~ Enemy Stamina " << enemyStamina << " ~\n";
         }
    }

    if (enemyHealing == false && enemyEffect == 3 && enemyStamina >= stamCost)
    {
    
    if (enemyPoison == true)
    {
        std::cout << "\n~ The Dragon winces at the pain of the poison (-5 HP) ~\n";
        enemyHealth -= 5;
        poisonL -= 1;
    }

    if (poisonL == 0)
    {
        std::cout << "== The Poison wears off ==\n";
    }

    if (EyeballActive == true)
    {
        std::cout << "\n~ The Dragon opens its mouth and shoots a fireball! ~\n";
        enemyStamina -= stamCost;

    if (fbpads == false)
    {
        health -= 25;
        std::cout << "(- 25 Health) ~\n";          
    }

    if (fbpads == true)
    {
        health -= 17;
        std::cout << "(-  17 Health) ~\n";
        std::cout <<"=== The Football Pads protect you a little! ===\n\n";
    }

        enemyHealth -=  50;
        
        enemyTurn = false;
        playerTurn = true;

        std::cout << "\n At the same instance its face blows up!\n";
        std::cout << "It hurt but not as much as it would have...\n";
        std::cout << "\n=== Enemy Health: " << enemyHealth << " ===\n\n";
        std::cout << "\n=== The Slime begins drying and no longer reflects damage! ===\n";

        EyeballActive = false;
        break;
    } 
    
    else if (EyeballActive == false)
    {

        enemyStamina -= stamCost;

    if (fbpads == false)
    {   
        health -= 50;
        std::cout << "(- 50 Health) ~\n\n";
    }
    if (fbpads == true)
    {
        health -= 35;
        std::cout << "(-  35 Health) ~\n";
        std::cout <<"=== The Football Pads protect you a little! ===\n\n";
            // 30% damage reduction
    }
            enemyHealing = false;
            enemyTurn = false;
            playerTurn = true;
            std::cout << "~ Enemy Stamina " << enemyStamina << " ~\n";
         }
    }

    if (enemyHealing == false && enemyEffect == 4 && enemyStamina >= stamCost)
    {

    if (enemyPoison == true)
    {
        std::cout << "\n~ The Dragon winces at the pain of the poison (-5 HP) ~\n";
        enemyHealth -= 5;
        poisonL -= 1;
    }

    if (poisonL == 0)
    {
        std::cout << "== The Poison wears off ==\n";
    }

    if (spiderDistract == true)
    {
        std::cout << "\n~ The Dragon is preoccupied with taking cobweb off its beak ~\n";
        std::cout << "\n~ He does not attack! ~\n";

        spiderDistract =  false;
        playerTurn = true;
        enemyTurn = false;
    }

    if (EyeballActive == true)
    {
        std::cout << "\n~ The Dragon swoops up anf flies down hitting you before landing!! ~";
        enemyStamina -= stamCost;

    if (fbpads == false)
    {
        health -= 35;
        std::cout << "(-  35 Health) ~\n";          
    }

    if (fbpads == true)
    {
        health -= 24;
        std::cout << "(-  24 Health) ~\n";
        std::cout <<"=== The Football Pads protect you a little! ===\n\n";
    }

        enemyHealth -=  70;
        
        enemyTurn = false;
        playerTurn = true;

        std::cout << "\n At the same instance the Dragon falls in enormous pain! \n";
        std::cout << "It hurt but not as much as it would have...\n";
        std::cout << "\n=== Enemy Health: " << enemyHealth << " ===\n\n";
        std::cout << "\n=== The Slime begins drying and no longer reflects damage! ===\n";

    EyeballActive = false; 
    break;
    } 
    
    else if (EyeballActive == false)
    {
        std::cout << "\n~ The Dragon swoops up and flies down hitting you before landing!! ";
        enemyStamina -= stamCost;

if (fbpads == false)
{   
    health -= 70;
    std::cout << "(- 70 Health) ~\n\n";
}
if (fbpads == true)
{
    health -= 49;
    std::cout << "(-  49 Health) ~\n";
    std::cout <<"=== The Football Pads protect you a little! ===\n\n";
    // 30% damage reduction
}
    enemyHealing = false;
    enemyTurn = false;
    playerTurn = true;
    std::cout << "~ Enemy Stamina " << enemyStamina << " ~\n";
    
       
}


 
    } // end of turn

                }

            }
    
        }   

    }
} 

int mimicsFight(int health , int attack, int stamina, int enemyHealth, int enemyStamina, bool fbpads, bool wand, bool bat, bool eyeball, bool fish, bool spiderFriend, bool PitLantern)
{
    srand(time(NULL));

if (bat == false)
{
    std::cout << "\n\nThe creature sees your lack of a weapon...\n";
    std::cout << "It lunges at you.";
    return 1;
}

std::cout << "\nThe creature turns to face you...\n\n";

bool playerTurn = true;
bool enemyTurn = false;

int playerEffect;
int enemyEffect;

string strat = "";

health = 100;
stamina = 25;
attack = 30;

enemyHealth = 70;
enemyStamina = 25;
bool enemyHealing = false;
int wandUses = 3;

while (enemyHealth > 0)
{
    while (playerTurn == true)
{
    if (health <= 0)
    {
        return 1;
    }

    std::cout << "\n-----------------------------------------------------------------------------------------\n";
    std::cout << "\n=== Health: " << health << " ===" << "\n=== Stamina: " << stamina << " ===\n \n";

if (items(wand, eyeball, fish, spiderFriend, PitLantern) == false)
{
std::cout << "What will you do? (attack [damages enemy] / rest [restores stamina and health + 10]): ";   
}
if (items(wand, eyeball, fish, spiderFriend, PitLantern) == true)
{
std::cout << "What will you do? (attack [damages enemy] / rest [restores stamina and health + 10] / items [Select one of your items in your inventory for use]): ";    
}


    std::cin >> strat;
    std::cout << "\n";

if (strat == "attack")
    {
        if (stamina < 5)
        {
            std::cout << "\n\n### You need AT LEAST-- 5 Stamina -- to attack! ### \n\n";
            continue;
        }

        playerEffect = getRandom();
        enemyEffect = getRandom();
        
        if (playerEffect == 1)
        {
            std::cout << "\nYou swing your Bat!\n";
            std::cout << "You completely MISS!!\n\n";

        }

        if (playerEffect == 2)
        {
            int change = attack * .2;

            std::cout << "\nYou swing your Bat!\n";
            attack -= change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Mimic ~ but just barely! You do " << attack << " damage! \n\n";
            attack = 30;

        }
        
        if (playerEffect == 3)
        {
            std::cout << "\nYou swing your Bat!\n";
            enemyHealth -= attack;
            std::cout << "You hit the ~ Mimic ~ and it connects! You do " << attack << " damage!\n\n";
        }
        
        if (playerEffect == 4)
        {
            std::cout << "\nYou swing your Bat!\n";
            int change = attack * .2;
            attack += change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Mimic ~ and it's a solid hit! You do " << attack << " damage! \n\n";
            attack = 30;
        }

        if (enemyHealth < 0)
        {
            enemyHealth = 0;
        }

        std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";
        stamina -= 5;

        playerTurn = false;
        enemyTurn = true;
        strat = "";
    }
if (strat == "rest")
{
     if (health == 100 && stamina == 25)
    {
        std::cout << "\n### You don't need to rest. You feel fine. ###\n";
        continue;
    }
    
    if (health < 100)
    {
        int h = 100 - health;

        if (h > 10)
        {
            std::cout << "\n Rested and restored +10 Health. ";
            health += 10;
        }

        if (h < 10)
        {
            std::cout << "\n Rested and restored +" << h << " Health.";
            health += h;
        }
    }

    if (stamina < 25)
    {
        int s = 25 - stamina;

        if (s > 10)
        {
            std::cout << "Rested and restored +10 Stamina.\n";
            stamina += 10;
        }

        if (s <= 10)
        {
            std::cout << "Rested and restored +" << s << " Stamina.\n";
            stamina += s;
        }
    }

    enemyTurn = true;
    playerTurn = false;
    strat = "";
    
}
if (strat == "mod")
    {
        enemyHealth = 0;
        enemyTurn = true;
        playerTurn = false;
    }
if (strat == "items" && items(wand, eyeball, fish, spiderFriend, PitLantern) == true)
    {
        std::cout << "\n=== Items (Select which one) ===\n\n";
        if (wand == true)
        {
            std::cout << "    Wand    \n";

        }
        if (eyeball == true)
        {
            std::cout << "    EyeBall    \n";
        }
        if (fish == true)
        {
            std::cout << "    Fish    \n";
        }

        std::cout << "\nSelect (cap sensitive): ";
        strat = "";
        std::cin >> strat;

        if (strat == "Wand")
        {

        if (wand == true)
        {
        strat = "";
        if (health == 100 && stamina == 25)
        {
            std::cout << "\n### You don't need to use the Wand. You feel fine. ###\n";
            continue;
        }
        std::cout << "\nYou wave the wand in the air. Sparks come out...\n\n";

        if (health < 100 && stamina < 25)
        {

            int h = 100 - health;

        if (h > 50)
        {
            std::cout << "\n=== The Wand heals 50 Health";
            health += 50;
        }

        if (h <= 50)
        {
            std::cout << "\n=== The Wand heals " << h << " Health";
            health += h;
        }

            stamina = 25;

            std::cout << " and maxes your Stamina ===\n\n";
        }

        if (health == 100 && stamina < 25)
        {
            stamina = 25;
            std::cout << "\n=== The Wand maxes your Stamina ===\n\n";
        }
        if (health < 100 && stamina == 25)
        {
             int h = 100 - health;

               if (h <= 50)
               {
                std::cout << "\n=== The Wand heals " << h << " Health";
                health += h;
               }

        }

        wandUses -= 1;

        if (wandUses == 1)
        {
            std::cout << "The wand fades from it's dark brown to a black color. If you use it again it WILL break... ===\n\n";
        }

        if (wandUses == 0)
        {
            std::cout << "The wand spazes out of your hand and explodes into a cloud of dust...\n\n";
            std::cout << "=== You LOSE the Wand ===\n\n";
            wand = false;
        }

        playerTurn = false;
        enemyTurn = true;
    } else if (wand == false)
    {
        std::cout << "\n### You do not own the Wand ###\n\n";
    }

        }
        
    
    }
}

while (enemyTurn == true)
{

    int stamCost = 10; 

            if (enemyHealth <= 0)
        {
            std::cout << "\n The Mimic shrieks as it returns to it's original form.\n";
            std::cout << "It cry echos through the cave and he suddently pops out of existence!\n";

            std::cout << "\n\n === The Mimic has Fallen ===\n\n";
            return 0;
        }
        
        if (enemyTurn == true)
        {
        if (enemyStamina < stamCost)
        {
            enemyHealing = true;
        }

        if (enemyStamina < 0)
        {
            enemyStamina = 0;
        }

        if (enemyStamina == 15)
        {
            enemyHealing = false;
        }

        if (enemyHealing)
        {
            enemyStamina += 10;

            if (enemyStamina > 25)
            {
                enemyStamina = 25;
            }

            std::cout << "~\n The Mimic pauses it's falsified form fading in and out... \n~";
            std::cout << "~ He seems to be taking a break and will begin attacking once he's done resting... ~\n\n";

            std::cout << "~ Enemy Stamina: +" << enemyStamina << " ~\n\n";
            //break;
        }


        if (enemyHealth < 10 && enemyHealth != 0)
        {
            std::cout << "~ The Mimic scratches it's stomach. ~\n";
            std::cout << "So much so that a little version of it comes out. ~\n";
            std::cout << "~ The little Mimic grows up in miliseconds and absorbs the power from the older Mimic!! ~\n";

            std::cout << "\n=== THE MIMIC HAS FULLY REGENERATED! ===\n\n";
            enemyHealth = 70;
        }

        if (enemyHealing == false && enemyEffect <= 2 && enemyStamina >= stamCost)
         {
            std::cout << "\n~ The Mimic morphs it into a Bat! He hits you!! ";
            enemyStamina -= stamCost;
            if (fbpads == false)
            {   
            health -= attack;
            std::cout << "(- " << attack << " Health) ~\n\n";
            }
            if (fbpads == true)
            {
                int r = (attack * .3);
                health -= attack - r;
                std::cout << "(- " << attack - r << " Health) ~\n";
                std::cout <<"=== The Football Pads protect you a little! ===\n\n";
                // 30% damage reduction
            }
            enemyHealing = false;
            std::cout << "~ Enemy Stamina " << enemyStamina << "~\n";
         }

        if (enemyHealing == false && enemyEffect == 3 && enemyStamina >= stamCost)
          {
            std::cout << "\n~ The Mimic morphs into a Bat and swings but you dodge! ~\n";
            enemyStamina -= stamCost;
           enemyHealing = false;
            std::cout << "\n~ Enemy Stamina " << enemyStamina << " ~\n\n";
          }

        if (enemyHealing == false && enemyEffect == 4 && enemyStamina >= stamCost)
           {
            std::cout << "\n~ The Mimic conjures all his energy and morphs into a spiked bat and hits you! It's a critical hit! ";
            enemyStamina -= stamCost;
            if (fbpads == false)
            {   
            std::cout << "(- 36 Health) ~\n";
            health -= 36;
            }
            if (fbpads == true)
            {
                health -= 30;
                std::cout << "(- 30 Health) ~\n";
                std::cout <<"\n=== The Football Pads protect you a little! ===\n";
                // 30% damage reduction
            }

            std::cout << "\n~ Enemy Stamina " << enemyStamina << " ~\n\n";
            std::cout << "\n-----------------------------------------------------------------------------------------\n";

            enemyHealing = false;
           }


        }

           enemyTurn = false;
           playerTurn = true;
    }   

}

}   

int skeletonFight(int health , int attack, int stamina, int enemyHealth, int enemyStamina, bool fbpads, bool wand, bool sword, bool PitLantern, bool PitBlessing, bool eyeball, bool fish, bool spiderFriend)
{

srand(time(NULL));

if (sword == false)
{
    std::cout << "\n\nThe skeleton sees your lack of a weapon...\n";
    std::cout << "It lunges at you. Impaling you!";
    return 1;
}

system("CLS");
std::cout << "\nThe skeleton cracks his knuckles...\n\n";

bool playerTurn = true;
bool enemyTurn = false;

int playerEffect;
int enemyEffect;

string strat = "";
if (PitBlessing == true)
{
health = 130;
}

if (PitBlessing == false)
{
health = 100;    
}

stamina = 25;
attack = 50;

enemyHealth = 80;
enemyStamina = 40;

bool enemyHealing = false;
int wandUses = 3; 

while (playerTurn == true)
{
    if (health <= 0)
    {
        return 1;
    }

    std::cout << "\n-----------------------------------------------------------------------------------------\n";
    std::cout << "\n=== Health: " << health << " ===" << "\n=== Stamina: " << stamina << " ===\n \n";


if (items(wand, eyeball, fish, spiderFriend, PitLantern) == false)
{
std::cout << "What will you do? (attack [damages enemy] / rest [restores stamina and health + 10]): ";   
}
if (items(wand, eyeball, fish, spiderFriend, PitLantern) == true)
{
std::cout << "What will you do? (attack [damages enemy] / rest [restores stamina and health + 10] / items [Select one of your items in your inventory for use]): ";    
}


    std::cin >> strat;
    std::cout << "\n";

if (strat == "attack")
    {
        if (stamina < 10)
        {
            std::cout << "\n\n### You need AT LEAST-- 10 Stamina -- to attack! ### \n\n";
            continue;
        }

        playerEffect = getRandom();
        enemyEffect = getRandom();
        
        if (playerEffect == 1)
        {
            std::cout << "\nYou swing your Sword!\n";
            std::cout << "You completely MISS!!\n\n";

        }

        if (playerEffect == 2)
        {
            int change = attack * .2;

            std::cout << "\nYou swing your Sword!\n";
            attack -= change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Skeleton ~ but just barely! You do " << attack << " damage! \n\n";
            attack = 50;

        }
        
        if (playerEffect == 3)
        {
            std::cout << "\nYou swing your Sword!\n";
            enemyHealth -= attack;
            std::cout << "You hit the ~ Skeleton ~ and it connects! You do " << attack << " damage!\n\n";
        }
        
        if (playerEffect == 4)
        {
            std::cout << "\nYou swing your Sword!\n";
            int change = attack * .2;
            attack += change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Skeleton ~ and it's a solid hit! You do " << attack << " damage! \n\n";
            attack = 50;
        }

        if (enemyHealth < 0)
        {
            enemyHealth = 0;
        }

        std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";
        stamina -= 10;
        playerTurn = false;
        enemyTurn = true;
        strat = "";

    }

if (strat == "rest")
{
     if (health == 100 && stamina == 25)
    {
        std::cout << "\n### You don't need to rest. You feel fine. ###\n";
        continue;
    }
    
    if (health < 100)
    {
        int h = 100 - health;

        if (h > 10)
        {
            std::cout << "\n Rested and restored +10 Health. ";
            health += 10;
        }

        if (h < 10)
        {
            std::cout << "\n Rested and restored +" << h << " Health.";
            health += h;
        }
    }

    if (stamina < 25)
    {
        int s = 25 - stamina;

        if (s > 10)
        {
            std::cout << "Rested and restored +10 Stamina.\n";
            stamina += 10;
        }

        if (s <= 10)
        {
            std::cout << "Rested and restored +" << s << " Stamina.\n";
            stamina += s;
        }
    }

    enemyTurn = true;
    playerTurn = false;
    strat = "";
    }

if (strat == "mod")
{
    enemyHealth = 0;
    enemyTurn = true;
    playerTurn = false;
}



while (enemyTurn == true)
    {

    int stamCost = 5; 

            if (enemyHealth <= 0)
        {
            std::cout << "\n The Skeletons bones shake...\n";
            std::cout << "You stand back as the Skeleton screams deeply and vanishes into thing air\n";

            std::cout << "\n\n === The Skeleton has Fallen ===\n";
            return 0;
        }
        
        if (enemyTurn == true)
        {
        if (enemyStamina < stamCost)
        {
            enemyHealing = true;
        }

        if (enemyStamina < 0)
        {
            enemyStamina = 0;
        }

        if (enemyStamina == 40)
        {
            enemyHealing = false;
        }

        if (enemyHealing)
        {
            enemyStamina += 15;

            if (enemyStamina > 40)
            {
                enemyStamina = 40;
            }

            std::cout << "~\n The Skeleton takes out a glass of milk and begins drinking... \n~";
            std::cout << "~ He seems to be taking a break and will begin attacking once he's done resting... ~\n\n";

            std::cout << "~ Enemy Stamina: +" << enemyStamina << " ~\n\n";
            enemyTurn = false;
            playerTurn = true;
            break;
        }


        if (enemyHealing == false && enemyEffect <= 2 && enemyStamina >= stamCost)
         {
            std::cout << "\n~ The Skeleton rushes in and punches your gut!! ";
            enemyStamina -= stamCost;
            if (fbpads == false)
            {   
            health -= 25;
            std::cout << "(- 25 Health) ~\n\n";
            }
            if (fbpads == true)
            {
                health -= 20;
                std::cout << "(-  20 Health) ~\n";
                std::cout <<"=== The Football Pads protect you a little! ===\n\n";
                // 30% damage reduction
            }
            enemyHealing = false;
            enemyTurn = false;
            playerTurn = true;
            std::cout << "~ Enemy Stamina " << enemyStamina << "~\n";
         }

        if (enemyHealing == false && enemyEffect == 3 && enemyStamina >= stamCost)
          {
            std::cout << "\n~ The Skeleton rushes in to punch you but you dodge! ~\n";
            enemyStamina -= stamCost;
           enemyHealing = false;
           enemyTurn = false;
           playerTurn = true;
            std::cout << "\n~ Enemy Stamina " << enemyStamina << " ~\n\n";
          }

        if (enemyHealing == false && enemyEffect == 4 && enemyStamina >= stamCost)
           {
            std::cout << "\n~ The Skeleton rushes in and impales you! It does crazy damage! ";
            enemyStamina -= stamCost + 30;
            if (fbpads == false)
            {   
            std::cout << "(- 70 Health) ~\n";
            health -= 70;
            }
            if (fbpads == true)
            {
                health -= 50;
                std::cout << "(- 50 Health) ~\n";
                std::cout <<"\n=== The Football Pads protect you a little! ===\n";
                // 30% damage reduction
            }

            std::cout << "\n~ Enemy Stamina " << enemyStamina << " ~\n\n";
            std::cout << "\n-----------------------------------------------------------------------------------------\n";

            enemyHealing = false;
           enemyTurn = false;
           playerTurn = true;
           }


        }
    }   


}
}

int spiderFight(int health , int attack, int stamina, int enemyHealth, int enemyStamina, bool fbpads, bool sword, bool pitBlessing, bool wand, bool eyeball, bool fish, bool spiderFriend, bool PitLantern)
{
    srand(time(NULL));

if (fish == false)
{
std::cout << "\nThe Spider hisses at you!\n";    
}

if (fish == true)
{
std::cout << "\nThe Spider's stomach grumbles! It may be hungry!!\n";    
   
}


if (sword == false)
{
    std::cout << " The Spider sees your lack of weapon...\n";
    std::cout << "He lunges at you...\n";
}

bool playerTurn = true;
bool enemyTurn = false;

int playerEffect;
int enemyEffect;
int LEffect;

string strat = "";
if (pitBlessing == false)
{
health = 100;
}
if (pitBlessing == true)
{
std::cout << "\n--- The Pit Grants you with 30 extra HP! ---\n";
health = 130;
}
stamina = 25;
attack = 50;

enemyHealth = 120;
enemyStamina = 20;
bool enemyHealing = false;

int wandUses = 3;
bool EyeballActive = false;
int pitUses = 1;

while (playerTurn == true)
{
if (health <= 0)
{
    return 1;
}

    std::cout << "\n-----------------------------------------------------------------------------------------\n";
    std::cout << "\n=== Health: " << health << " ===" << "\n=== Stamina: " << stamina << " ===\n \n";


if (items(wand, eyeball, fish, spiderFriend, PitLantern) == false)
{
std::cout << "What will you do? (attack [damages enemy] / rest [restores stamina and health + 10]): ";   
}
if (items(wand, eyeball, fish, spiderFriend, PitLantern) == true)
{
std::cout << "What will you do? (attack [damages enemy] / rest [restores stamina and health + 10] / items [Select one of your items in your inventory for use]): ";    
}

    std::cin >> strat;
    std::cout << "\n";

if (strat == "attack")
    {
        if (stamina < 10)
        {
            std::cout << "\n\n### You need AT LEAST-- 10 Stamina -- to attack! ### \n\n";
            continue;
        }

        playerEffect = getRandom();
        enemyEffect = getRandom();
        
        if (playerEffect == 1)
        {
            std::cout << "\nYou swing your Sword!\n";
            std::cout << "You completely MISS!!\n\n";

        }

        if (playerEffect == 2)
        {
            int change = attack * .2;

            std::cout << "\nYou swing your Sword!\n";
            attack -= change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Spider ~ but just barely! You do " << attack << " damage! \n\n";
            attack = 50;

        }
        
        if (playerEffect == 3)
        {
            std::cout << "\nYou swing your Sword!\n";
            enemyHealth -= attack;
            std::cout << "You hit the ~ Spider ~ and it connects! You do " << attack << " damage!\n\n";
        }
        
        if (playerEffect == 4)
        {
            std::cout << "\nYou swing your Sword!\n";
            int change = attack * .2;
            attack += change;
            enemyHealth -= attack;
            std::cout << "You hit the ~ Spider ~ and it's a solid hit! You do " << attack << " damage! \n\n";
            attack = 50;
        }

        if (enemyHealth < 0)
        {
            enemyHealth = 0;
        }

        std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";
        stamina -= 10;
        playerTurn = false;
        enemyTurn = true;
        strat = "";

    }

if (strat == "rest")
{
    if (pitBlessing == false)
    {
     if (health == 100 && stamina == 25)
    {
        std::cout << "\n### You don't need to rest. You feel fine. ###\n";
        continue;
    }        
    }

    if (pitBlessing == true)
    {
    if (health == 130 && stamina == 25)
    {
        std::cout << "\n### You don't need to rest. You feel fine. ###\n";
        continue;
    }   
    }

if (pitBlessing == false)
{
if (health < 100)
    {
        int h = 100 - health;

        if (h > 10)
        {
            std::cout << "\n Rested and restored +10 Health. ";
            health += 10;
        }

        if (h < 10)
        {
            std::cout << "\n Rested and restored +" << h << " Health.";
            health += h;
        }
    }    
}

if (pitBlessing == true)
{
if (health < 130)
    {
        int h = 130 - health;

        if (h > 10)
        {
            std::cout << "\n Rested and restored +10 Health. ";
            health += 10;
        }

        if (h < 10)
        {
            std::cout << "\n Rested and restored +" << h << " Health.";
            health += h;
        }
    }  
}
    

    if (stamina < 25)
    {
        int s = 25 - stamina;

        if (s > 10)
        {
            std::cout << "Rested and restored +10 Stamina.\n";
            stamina += 10;
        }

        if (s <= 10)
        {
            std::cout << "Rested and restored +" << s << " Stamina.\n";
            stamina += s;
        }
    }

    enemyTurn = true;
    playerTurn = false;
    strat = "";
    }

if (strat == "mod")
{
    enemyHealth = 0;
    enemyTurn = true;
    playerTurn = false;
}

if (strat == "items" && items(wand, eyeball, fish, spiderFriend, PitLantern) == true)
{
    std::cout << "\n=== Items (Select which one) ===\n\n";
if (wand == true)
        {
            std::cout << "    Wand    \n";

        }
if (eyeball == true)
        {
            std::cout << "    EyeBall    \n";
        }        
if (fish == true)
        {
            std::cout << "    Fish    \n";
        }
if (PitLantern == true)
    {
        std::cout << "   Pit Lantern (Type Pit to Select)   \n";
    }

    std::cout << "\nSelect (cap sensitive): ";
    strat = "";
    std::cin >> strat;

if (strat == "Wand")
{

if (wand == true)
{
    strat = "";
if (health == 100 && stamina == 25)
{
    std::cout << "\n### You don't need to use the Wand. You feel fine. ###\n";
    continue;
}
    std::cout << "\nYou wave the wand in the air. Sparks come out...\n\n";

if (health < 100 && stamina < 25)
{

    int h = 100 - health;

if (h > 50)
{
    std::cout << "\n=== The Wand heals 50 Health";
    health += 50;
}

if (h <= 50)
{
    std::cout << "\n=== The Wand heals " << h << "Health";
    health += h;
}

    stamina = 25;

    std::cout << " and maxes your Stamina ===\n\n";
}

if (health == 100 && stamina < 25)
{
    stamina = 25;
    std::cout << "\n=== The Wand maxes your Stamina ===\n\n";
}

if (health < 100 && stamina == 25)
{
    int h = 100 - health;

if (h <= 50)
{
    std::cout << "\n=== The Wand heals " << h << " Health";
    health += h;
    }
}

    wandUses -= 1;

if (wandUses == 1)
{
    std::cout << "The wand fades from it's dark brown to a black color. If you use it again it WILL break... ===\n\n";
}

if (wandUses == 0)
{
    std::cout << "The wand spazes out of your hand and explodes into a cloud of dust...\n\n";
    std::cout << "=== You LOSE the Wand ===\n\n";
    wand = false;
}

    playerTurn = false;
    enemyTurn = true;
} else if (wand == false)
{
    std::cout << "\n### You do not own the Wand ###\n\n";
}

}
        
if (strat == "EyeBall")
{
    std::cout << "\n=== You hold the EyeBall in front of you ===";
    EyeballActive = true;
}

if (strat == "Fish")
{
    std::cout << "\n=== The Spider relaxes as it sees the fish in your hand ===\n";
    return 2;
}

if (strat == "Pit")
{

if (pitUses == 0)
{
    std::cout << "\n## The Lantern seems dim. Try again next round ##\n";
    continue;
}

if (pitUses == 1)
{
    std::cout << "\n=== The Lantern Glows Brightly ===\n";
    int LEffect = getRandom();

    if (LEffect == 1)
{
    std::cout << "== The Lantern fires a beam of light! ==\n";
    enemyHealth -= 5;   
    std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";
    pitUses -= 1;

}

if (LEffect == 2)
{
    std::cout << "== The Lantern shines and fires powerful beam of light! Damaging the boss! ==";
    enemyHealth -= 15;
    std::cout << "\n=== Enemy Health: " << enemyHealth << " ===\n";   
    pitUses -= 1;
}

if (LEffect == 3)
{
    std::cout << "== The Lantern shines and fires powerful beam of light! Damaging the boss! ==";
    enemyHealth -= 15;
    std::cout << "\n=== Enemy Health: " << enemyHealth << " ===\n\n";   
    pitUses -= 1;
}

if (LEffect == 4)
{
    std::cout << "== The Lantern rattles and shakes and rattles ==\n";
    std::cout << "== The orange flame turns black and a white beam shoots out doing INCREDIBLE DAMAGE! ==\n";
    enemyHealth -= 40;
    std::cout << "=== Enemy Health: " << enemyHealth << " ===\n\n";
    pitUses -= 1;

}
}

}    

}

while (enemyTurn == true)
{

    int stamCost = 5;
    pitUses += 1;

    if (pitUses > 1)
    {
        pitUses = 1;
    }

    if (enemyHealth <= 0)
        {
            std::cout << "\n The Spider flies back from your attack...\n";
            std::cout << "It lands into one of its webs as its legs curl up.\n";

            std::cout << "\n === The Spider has Fallen ===\n\n";
            return 0;
        }
        
    if (enemyTurn == true)
    {
if (enemyStamina < stamCost)
        {
            enemyHealing = true;
        }

if (enemyStamina < 0)
        {
            enemyStamina = 0;
        }

if (enemyStamina == 20)
        {
            enemyHealing = false;
        }

if (enemyHealing)
        {
            enemyStamina += 5;

            if (enemyStamina > 20)
            {
                enemyStamina = 20;
            }

            std::cout << "\n~ The Spider scurries into its webs... ~\n";
            std::cout << "~ He seems to be taking a break and will begin attacking once he's done resting... ~\n\n";

            std::cout << "~ Enemy Stamina: +" << enemyStamina << " ~\n\n";
            enemyTurn = false;
            playerTurn = true;
            break;
        }



if (enemyHealing == false && enemyEffect <= 2 && enemyStamina >= stamCost)
{
    std::cout << "\n~ The Spider rushes at you and slashes you with it's fangs!! ";
    enemyStamina -= stamCost;
if (fbpads == false)
{   
    health -= 25;
    std::cout << "(- 25 Health) ~\n\n";
}
if (fbpads == true)
{
    health -= 20;
    std::cout << "(-  20 Health) ~\n";
    std::cout <<"=== The Football Pads protect you a little! ===\n\n";
    // 30% damage reduction
}
    enemyHealing = false;
    enemyTurn = false;
    playerTurn = true;
    std::cout << "~ Enemy Stamina " << enemyStamina << "~\n";
}

if (enemyHealing == false && enemyEffect == 3 && enemyStamina >= stamCost)
{
    std::cout << "\n~ The Spider attempts to bite but you dodge ~\n";
    enemyStamina -= stamCost;
    enemyHealing = false;
    enemyTurn = false;
    playerTurn = true;
    std::cout << "\n~ Enemy Stamina " << enemyStamina << " ~\n\n";
}

if (enemyHealing == false && enemyEffect == 4 && enemyStamina >= stamCost)
{
    std::cout << "\n~ The Spider rushes to attack and headbutts you in the gut! It does a lot of damage! ";
    enemyStamina -= stamCost;
if (fbpads == false)
{   
    std::cout << "(- 70 Health) ~\n";
    health -= 70;
}
if (fbpads == true)
{
    health -= 50;
    std::cout << "(- 50 Health) ~\n";
    std::cout <<"\n=== The Football Pads protect you a little! ===\n";
    // 30% damage reduction
}

std::cout << "\n~ Enemy Stamina " << enemyStamina << " ~\n\n";
std::cout << "\n-----------------------------------------------------------------------------------------\n";

enemyHealing = false;
enemyTurn = false;
playerTurn = true;
                
                }
            }
        
        }   
    }
}

int main()
{
    string advance = "";
    string collect = "";
    string strat = "";

    int health = 100;

    int damage = 0;
    int attack = 0;
    int stamina = 0;

    int enemyHealth = 0;
    int enemyStamina = 0;

    bool sword = false;
    bool key = false;
    bool bat = false;
    bool xbow = false;
    bool fbpads = false;

    bool wand = false;
    bool fish = false;
    bool GuardSword = false;
    bool Eyeball = false;

    bool skull = false;
    bool flesh = false;
    bool PitLantern = false; 

    bool pitBlessing = false;
    bool pitVisted = false;
    bool spiderFriend = false;


    std::cout << "You wake up in a dungeon. Your goal is to survive.\n\n";
    Sleep(1000);
    while (true)
    {

    while (advance != "yes" && advance != "no") {
        std::cout << "There are writings on the wall. Read? (yes/no): ";
        std::cin >> advance;
    }


    if (advance == "yes") 
    {
        std::cout << "It says --- THIS IS THE TOMB OF THE ANCIENT. LEFT TO ROT. --- \n \n";
        Sleep(1200);
        advance = "";
    } else if (advance == "no")
    {
        std::cout << "You don't read the wall... \n";
        Sleep(0700);
        advance = "";
    }


while (advance != "yes") {


    std::cout << "Do you want to advance? (yes/no): ";
    std::cin >> advance;

    if (advance == "yes") {
            std::cout << "You advance! \n\n";

    } else {
            std::cout << "You must advance to survive. \n";
            continue;    
    }
}

while (advance != "right" && advance != "left")
{
    std::cout << "The path ahead splits in two. Which way do you go? (right/left): ";
    std::cin >>  advance;
        
if (advance == "right")
{
        std::cout << "\n=== You find a Sword in this room! === \n";
while (collect != "yes" && collect != "no")
{   
    std::cout << "Collect the Sword? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
    std::cout << "--- Sword added to your inventory --- \n\n";
    std::cout << "___Inventory___\n";
                     
            sword = true;

if (xbow == true) {std::cout << "    Crossbow    \n";};
if (sword == true) {std::cout << "    Sword    \n";};
if (fish == true){std::cout << "     Fish     \n";};
if (pitBlessing == true){std::cout << "\n___Effects___\n Pit Blessing (+30 Health)\n";};


} 

if (collect == "no")
{
    std::cout << "--- You left the Sword behind... --- \n";
}

    std::cout << "The path splits two ways. Right, and forward\n\n";
    advance = "";

while (advance != "right" && advance != "forward")
{
    std::cout << "Which way will you go (right/forward): ";
    std::cin >> advance;
            

if (advance == "right")
{
    pitVisted = true;
    std::cout << "You enter a dark, magical room.\n";
    std::cout << "It has a huge hole in the middle...\n\n";
    std::cout << "???: You're not supposed to be here! \n\n";
    std::cout << "The ground rumbles. The pit speaks!!\n\n";
    std::cout << "Sentient Pit: Since you are down here. Give me an item and I will reward you...\n\n";

            collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "\n Will you offer the Pit an item?(yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
    std::cout << "What item will give you give? (say cancel to cancel): ";
    collect = "";
    std::cin >> collect;

while (collect != "cancel")
{

if (sword == true && collect == "sword")
{
    std::cout << "\nYou throw your Sword in...\n";
    bool pitBlessing = true;
    std::cout << "\nSentient Pit: MMMM!! Excellect, I've increased your health by 30 points!";
    std::cout << "\n=== The Pit throws you a lantern! ===\n";
    std::cout << "\nSentient Pit: Use this in combat as well. It has ALMOST all the power I have!\n";
    std::cout << "--- Pit Lantern Added to Inventory ---";
    PitLantern = true;

        std::cout << "\n___Inventory___ \n";

if (xbow == true) {std::cout << "    Crossbow    \n";};
if (sword == true) {std::cout << "    Sword    \n";};
if (fish == true){std::cout << "     Fish     \n";};
if (PitLantern == true){std::cout << "  Pit Lantern  \n";};
if (spiderFriend == true){std::cout << "__Companions__\n   Spider Friend";};


    health = 130;
    break;
}


if (collect == "cancel")
{
    std::cout << "\n You exit the room...\n\n";
    std::cout << "Sentient Pit: Come back to me soon. The offer still stands!\n\n";
}
} 

}

if (collect == "no")
{
    std::cout << "\n You exit the room...\n";
    std::cout << "\nSentient Pit: Come back to me soon. The offer still stands!\n\n";
}
}
        
    std::cout << "\nThe pit room has one door to advance into. In the right corner.\n";
    pitVisted = true;
    advance = "";

while (advance != "yes" && advance != "no")
{
    std::cout << "Will you advance?(yes/no): ";
    std::cin >> advance;
if (advance == "no")
{
    std::cout << "\n\nSentient Pit: Leave before I take you as a sacrifice!\n";
    continue;
}
if (advance == "yes")
{
    std::cout << "\n You exit the room...\n";
    std::cout << "\nYou wander into what looks to be a morgue...\n";
    std::cout << "You hear rattling across the room and you turn...\n";
    std::cout << "\n=== You see a skeleton! ===\n";
    int a = skeletonFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, sword, PitLantern, pitBlessing, Eyeball, fish, spiderFriend);

if (a == 0)
{
    std::cout << "\n\nThe only remains of the Skeleton is it's skull as it clunks on the floor...\n\n";

if (pitBlessing == false && pitVisted == true)
{
    std::cout << "\nYou see no use of it other than to give to the == Sentient Pit ==\n";
            
    std::cout << "Will you bring the === Skeleton Skull === to the Pit (yes/no)?: ";
    std::cin >> advance;

if (advance == "yes")
{
    std::cout << "\nLike the Pit can hear your thoughts it summons under you making the ground fall inward.\n";
    std::cout << "It sucks the skull in.\n\n";
    std::cout << "Sentient Pit: MMMM! Tastes like a fresh kill! Your donation has increased your health by 30 points!\n\n";
    std::cout << "=== The Pit throws you a lantern! ===\n";
    std::cout << "\nSentient Pit: Use this in combat as well. It has ALMOST all the power I have!\n";
    std::cout << "--- Pit Lantern Added to Inventory ---\n";
    PitLantern = true;
    pitBlessing = true;

    std::cout << "\n___Inventory___ \n";

if (xbow == true) {std::cout << "    Crossbow    \n";};
if (sword == true) {std::cout << "    Sword    \n";};
if (fish == true){std::cout << "     Fish     \n";};
if (PitLantern == true){std::cout << "  Pit Lantern  \n";};
if (spiderFriend == true){std::cout << "__Companions__\n   Spider Friend";};
std::cout << endl;

    pitBlessing = true;
}

if (advance == "no")
{
    std::cout << "\nYou throw the skull to the side.\n";
    std::cout << "That THING was probably lying.";
        }
    }
}

if (a == 1)
{
            std::cout << "\n\n=== YOU DIED ===";
            return 0;
            }
        }
    }

}

//Skeleton Fight
if (advance == "forward")
{
    std::cout << "\nYou wander into what looks to be a morgue...\n";
    std::cout << "You hear rattling across the room and you turn...\n";
    std::cout << "\n=== You see a skeleton! ===\n";
    int a = skeletonFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, sword, PitLantern, pitBlessing, Eyeball, fish, spiderFriend);

if (a == 0)
{
    std::cout << "\n\nThe only remains of the Skeleton is it's skull as it clunks on the floor...\n\n";
        
}

if (a == 1)
{
    std::cout << "\n\n=== YOU DIED ===";
    return 0;
    }
}

    std::cout << "The path ahead splits in two ways.\n";
        
    advance = "";

while (advance != "right" && advance != "left")
{
    std::cout << "Which way will you go?(right/left): ";
    std::cin >> advance;

// Spider Fight (without chance of taming)
if (advance == "right")
{
    std::cout << "\nYou enter a bedroom that is covered in cobwebs!\n";
    std::cout << "In the corner you hear soft hissing...\n";
    system("CLS");
    std::cout << "=== A Spider emerges from the web ===\n";

    int a = spiderFight(health ,attack, stamina, enemyHealth,enemyStamina,fbpads, sword, pitBlessing, wand, Eyeball, fish, spiderFriend, PitLantern);

if (a == 0)
{
if (pitBlessing == false && pitVisted == true)
{
    std::cout << "=== The Spider drops some web! ==="; 
    collect = "";

while (collect != "yes" && collect != "no")
{
    std::cout << "Will you offer this to the Pit? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
    std::cout << "\nLike the Pit can hear your thoughts it summons under you making the ground fall inward.\n";
    std::cout << "It sucks the web in.\n\n";
    std::cout << "Sentient Pit: MMMM! Tastes like a fresh kill! Your donation has increased your health by 30 points!\n\n";
    pitBlessing = true;
    PitLantern = true; 
}

if (collect == "no")
{
    std::cout << "\nYou throw the Web to the side.\n";
    std::cout << "That THING was probably lying.";
            }
        }
    }
}

if (a == 1)
{
    std::cout << "\n\n\n=== YOU DIED ===";
    return 0;
}

advance = "";

while (advance != "yes" && advance != "no")
{
    std::cout << "Ahead of you is only one path. Enter? (yes/no): ";
    std::cin >> advance;

if (advance == "yes")
{
    std::cout << "\nYou walk into a room that looks an armory.\n";\
    std::cout << "\n=== There is a Crossbow on the Wall! ===\n\n";

    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "Will you collect the Crossbow?(yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
 
if (sword == true)
{
        collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "\nAre you sure you want to replace your Sword? (yes/no): ";
    std::cin >> collect;
if (collect == "yes")
{
    std::cout << "--- Crossbow added to your inventory --- \n";
    xbow = true;
    sword = false;

    std::cout << "\n___Inventory___ \n";

if (xbow == true) {std::cout << "    Crossbow    \n";};
if (sword == true) {std::cout << "    Sword    \n";};
if (fish == true){std::cout << "     Fish     \n";};
if (PitLantern == true){std::cout << "  Pit Lantern  \n";};
if (spiderFriend == true){std::cout << "__Companions__\n   Spider Friend";};
std::cout << endl;
        
            }
        }
    }
}

if (collect == "no")
{
    std::cout << "\n--- You left the Crossbow behind ---\n";
    }
}

advance = "";

while (advance != "yes" && advance != "no")
{
std::cout << "\nThere is only one more ominous path. Will you proceed? (yes/no): ";
std::cin >> advance;

if (advance == "yes")
{
std::cout << "\n You wander into the dark hallway... \n";
    Sleep(1200);
    std::cout << "The hallway gets hotter as you approach. \n";
    Sleep(1200);
    std::cout << "A huge metal door faded in from the dark infront of you. \n";
    Sleep(1200);
    std::cout << "\n === The door is locked but has a key hole === \n";
    Sleep(1000);


        advance = "";

if (key == false)
{
    std::cout << "\nYou have nothing to unlock the door with.\n";
    Sleep(1200);
    std::cout << "You start to head back. When you hear heavy steps ahead of you. \n";
    Sleep(1200);
    std::cout << "\n~ A huge man appears ahead of you ~ \n";
    Sleep(1200);
    std::cout << "\n=== He offers to open the door if you best him in 1 on 1 combat === \n";
    strat = "";

while (strat != "yes" && strat != "no")
{
    Sleep(1200);

    std::cout << "\nDo you accept his offer? (yes/no): ";
    std::cin >> strat;

if (strat == "no")
{
    std::cout << "The large man grows angry with you. \n";
    Sleep(0700);
    std::cout << "He unsheaths his heavy sword and swings it at you neck, killing you. \n";

    std::cout << "\n=== YOU DIED === \n";
    return 0;
}
if (strat == "yes")
{

if (sword == false && xbow == false)
{
    std::cout << "\nThe large man sees your lack of weapon and gros angry. \n";
    Sleep(0700);
    std::cout << "\nHe unsheaths his heavy sword and swings it at you neck, killing you. \n";

    std::cout << "=== YOU DIED === \n";
    return 0;    
} else 
{
    system("CLS");
    std::cout << "You prepare for battle!";
    Sleep(1200);

    int a = guardFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, sword, Eyeball, fish, pitBlessing, xbow, spiderFriend, PitLantern);

if (a == 0)
{
    std::cout << "\n=== The Guard Drops his Sword! ===\n\n";
    std::cout << "It's a beautifully crafted sword sure to do damage! === It will replace your Bat. ===\n";
    collect = "";

while (collect != "yes" && collect != "no")
{
    std::cout << "\nWill you collect the Guards Sword? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
    std::cout << "\n--- Guard Sword added to inventory ---\n\n";
if (sword == true)
{

}

if (xbow == true)
{

}
    GuardSword = true;

    std::cout << "___Inventory___\n\n";

if (GuardSword == true){std::cout << "  Guard Sword \n";};
std::cout << "\n___Inventory___ \n";

if (xbow == true) {std::cout << "    Crossbow    \n";};
if (sword == true) {std::cout << "    Sword    \n";};
if (fish == true){std::cout << "     Fish     \n";};
if (PitLantern == true){std::cout << "  Pit Lantern  \n";};
if (spiderFriend == true){std::cout << "__Companions__\n   Spider Friend";};
std::cout << endl;


}
            if (collect == "no")
            {
                std::cout << "\n--- You leave the Guard Sword behind... ---\n\n";
            }

                std::cout << "\n The huge metal door slides open. You hear a mumbled growling coming from inside...\n";
                std::cout << "For some reason you can that this is the end of the dungeon...\n\n";

                advance = "";

            while (advance != "yes" && advance != "no")
            {
                std::cout << "Will you advance? (yes/no): ";
                std::cin >> advance;

            if (advance == "yes")
            {
                std::cout << "\nYou advance into the dark purple lit room...";
                int a = dragonFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, sword, Eyeball, fish, pitBlessing, xbow, spiderFriend, PitLantern, GuardSword);
            
            if (a == 0)
            {
                return 0;
            }
            
            if (a == 1)
            {
                std::cout << "\n\n=== YOU DIED ===\n";
                return 0;
            }
            }

            if (advance == "no")
            {
                std::cout << "\nThere seems to be no where else to go...\n";
                continue;
            }
                    }
                }
            } else if (a == 1)
            {
                    std::cout << "\n\n == YOU DIED ==";
                    return 0;
            }
            }

            }
            }
            }

if (advance == "no")
{
    std::cout << "\nThere is no where else to go...\n";
    continue;
}

    }
}

}

}
}
}

if (advance == "left")
{
    std::cout << "\nYou wander into an extremly smelly room!\n";
    std::cout << "There a bunch of tables cover with fish dead and alive.\n";
    std::cout << "There is only one Fish that seems good to eat in a tank.\n\n";

    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "Will you take the Fish? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
    std::cout << "--- Fish added to your inventory --- \n";
    fish = true;

    std::cout << "\n___Inventory___ \n";

if (xbow == true) {std::cout << "    Crossbow    \n";};
if (sword == true) {std::cout << "    Sword    \n";};
if (fish == true){std::cout << "     Fish     \n";};
if (pitBlessing == true){std::cout << "\n___Effects___\n Pit Blessing (+30 Health)\n";};
        
    }

    if (collect == "no")
    {
        std::cout << "--- You left the Fish behind ---\n";
    }
    }

    std::cout << "\nThere are two paths to take. The one on the left looks ominous...";
    
    advance = "";

while (advance != "left" && advance != "right")
{
    cout << "Which way will you go? (left/right): ";
    cin >> advance;

// Guard Fight
if (advance == "left")
{
        std::cout << "\n You wander into the dark hallway... \n";
        Sleep(1200);
        std::cout << "The hallway gets hotter as you approach. \n";
        Sleep(1200);
        std::cout << "A huge metal door faded in from the dark infront of you. \n";
        Sleep(1200);

        std::cout << "\n === The door is locked but has a key hole === \n";
        Sleep(1000);


        advance = "";
    
if (key == false)
{
                
    std::cout << "\nYou have nothing to unlock the door with. Maybe == The Key == could've helped... \n";
    Sleep(1200);
    std::cout << "You start to head back. When you hear heavy steps ahead of you. \n";
    Sleep(1200);
    std::cout << "\n~ A huge man appears ahead of you ~ \n";
    Sleep(1200);
    std::cout << "\n=== He offers to open the door if you best him in 1 on 1 combat === \n";
    strat = "";

while (strat != "yes" && strat != "no")
{
    Sleep(1200);

    std::cout << "\nDo you accept his offer? (yes/no): ";
    std::cin >> strat;

if (strat == "no")
{
    std::cout << "The large man grows angry with you. \n";
    Sleep(0700);
    std::cout << "He unsheaths his heavy sword and swings it at you neck, killing you. \n";

    std::cout << "\n=== YOU DIED === \n";
    return 0;
}
if (strat == "yes")
{
if (sword == false)
{
    std::cout << "\nThe large man sees your lack of weapon and gros angry. \n";
    Sleep(0700);
    std::cout << "\nHe unsheaths his heavy sword and swings it at you neck, killing you. \n";

    std::cout << "=== YOU DIED === \n";
    return 0;    
} else 
{
    system("CLS");
    std::cout << "You prepare for battle!";
    Sleep(1200);

int a = guardFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, sword, Eyeball, fish, pitBlessing, xbow, spiderFriend, PitLantern);

if (a == 0)
{
    std::cout << "\n=== The Guard Drops his Sword! ===\n\n";
    std::cout << "It's a beautifully crafted sword sure to do damage! === It will replace your current Weapon. ===\n";
    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "\nWill you collect the Guards Sword? (yes/no): ";
    std::cin >> collect;
if (collect == "yes")
{

if (sword == true)
{    
    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "\nAre you sure you want to replace your Sword? (yes/no): ";

    std::cin >> collect;
if (collect == "yes")
{
    std::cout << "\n--- Guard Sword added to inventory ---\n\n";

    GuardSword = true;
    sword = false;

    std::cout << "\n___Inventory___ \n";

if (xbow == true) {std::cout << "    Crossbow    \n";};
if (sword == true) {std::cout << "    Sword    \n";};
if (fish == true){std::cout << "     Fish     \n";};
if (PitLantern == true){std::cout << "  Pit Lantern  \n";};
if (spiderFriend == true){std::cout << "__Companions__\n   Spider Friend";};
std::cout << endl;
}       
}

}

if (xbow == true)
{    
    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "\nAre you sure you want to replace your Crossbow? (yes/no) :";

    std::cin >> collect;
if (collect == "yes")
{
    std::cout << "\n--- Guard Sword added to inventory ---\n\n";

    GuardSword = true;
    xbow = false;

    std::cout << "\n___Inventory___ \n";

if (xbow == true) {std::cout << "    Crossbow    \n";};
if (sword == true) {std::cout << "    Sword    \n";};
if (fish == true){std::cout << "     Fish     \n";};
if (PitLantern == true){std::cout << "  Pit Lantern  \n";};
if (spiderFriend == true){std::cout << "__Companions__\n   Spider Friend";};
std::cout << endl;
}       
}

}
       
}

if (collect == "no")
{
    std::cout << "\n--- You leave the Guard Sword behind... ---\n\n";
}

    std::cout << "\n The huge metal door slides open. You hear a mumbled growling coming from inside...\n";
    std::cout << "For some reason you can that this is the end of the dungeon...\n";

    advance = "";

while (advance != "yes" && advance != "no")
{
    std::cout << "Will you advance? (yes/no): ";
    std::cin >> advance;

if (advance == "yes")
{
    std::cout << "\nYou advance into the dark purple lit room...";
    int a = dragonFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, sword, Eyeball, fish, pitBlessing, xbow, spiderFriend, PitLantern, GuardSword);

if (a == 0)
{
    return 0;
}
            
if (a == 1)
{
    std::cout << "\n\n=== YOU DIED ===\n";
    return 0;
}
}

if (advance == "no")
{
    std::cout << "\nThere seems to be no where else to go...\n";
    continue;
}
        }
    }
} else if (a == 1)
{
    std::cout << "\n\n == YOU DIED ==";
    return 0;
                    }
                }
            }
        }
    }
}

//Spider Fight (with fish)
if (advance == "right")
{
    std::cout << "\nYou eneter a bedroom that is covered in cobwebs!\n";
    std::cout << "In the corner you hear soft hissing...\n";
    system("CLS");
    std::cout << "=== A Spider emerges from the web ===\n";

    int a = spiderFight(health ,attack, stamina, enemyHealth,enemyStamina,fbpads, sword, pitBlessing, wand, Eyeball, fish, spiderFriend, PitLantern);

if (a == 0)
{
if (pitBlessing == false && pitVisted == true)
{
    std::cout << "=== The Spider drops some web! ==="; 
    collect = "";

while (collect != "yes" && collect != "no")
{
    std::cout << "Will you offer this to the Pit? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
    std::cout << "\nLike the Pit can hear your thoughts it summons under you making the ground fall inward.\n";
    std::cout << "It sucks the web in.\n\n";
    std::cout << "Sentient Pit: MMMM! Tastes like a fresh kill! Your donation has increased your health by 30 points!\n\n";
    pitBlessing = true;
    PitLantern = true; 
}

if (collect == "no")
{
    std::cout << "\nYou throw the Web to the side.\n";
    std::cout << "That THING was probably lying.";
                }
            }
        }
    }
if (a == 1)
{
    std::cout << "\n\n\n=== YOU DIED ===";
    return 0;
}

if (a == 2)
{
    std::cout << "\nThe Spider runs over to you and gobbles up the Fish in one bite!\n";

    std::cout << "\n=== You and the Spider are now friends!!! ===\n\n";

    spiderFriend = true;
    fish = false;

}

    std::cout << "There is only one path straight ahead.\n";

    advance = "";

while (advance != "yes" && advance != "no")
{
    std::cout << "Will you advance?(yes/no): ";
    std::cin >> advance;

if (advance == "yes")
{
    std::cout << "\nYou walk into a room that looks an armory.\n";\
    std::cout << "\n=== There is a Crossbow on the Wall! ===\n\n";

    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "Will you collect the Crossbow?(yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
if (sword == true)
{
    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "\nAre you sure you want to replace your Sword? (yes/no): ";
    std::cin >> collect;
    if (collect == "yes")
{
    std::cout << "--- Crossbow added to your inventory --- \n";
    xbow = true;
    sword = false;

    std::cout << "\n___Inventory___ \n";

if (xbow == true) {std::cout << "    Crossbow    \n";};
if (sword == true) {std::cout << "    Sword    \n";};
if (fish == true){std::cout << "     Fish     \n";};
if (pitBlessing == true){std::cout << "\n___Effects___\n Pit Blessing (+30 Health)\n";};
        
            }
        }
    }
}

if (collect == "no")
{
    std::cout << "\n--- You left the Crossbow behind ---\n";
        }
    }   
}

if (advance == "no")
{
    std::cout << "\n### You must advance to continue ###\n";
    continue;
    }
}

std::cout << "\nThere is only one path ahead. It's possibly your last\n";

advance = "";

while (advance != "yes" && advance != "no")
{
    std::cout << "Will you advance? (yes/no): ";
    std::cin >> advance;

if (advance == "yes")
{
    std::cout << "\n You wander into the dark hallway... \n";
    Sleep(1200);
    std::cout << "The hallway gets hotter as you approach. \n";
    Sleep(1200);
    std::cout << "A huge metal door faded in from the dark infront of you. \n";
    Sleep(1200);
    std::cout << "\n === The door is locked but has a key hole === \n";
    Sleep(1000);
    
    advance = "";

if (key == false)
{
    std::cout << "\nYou have nothing to unlock the door with... \n";
    Sleep(1200);
    std::cout << "You start to head back. When you hear heavy steps ahead of you. \n";
    Sleep(1200);
    std::cout << "\n~ A huge man appears ahead of you ~ \n";
    Sleep(1200);
    std::cout << "\n=== He offers to open the door if you best him in 1 on 1 combat === \n";
    strat = "";

while (strat != "yes" && strat != "no")
{
    Sleep(1200);

    std::cout << "\nDo you accept his offer? (yes/no): ";
    std::cin >> strat;

if (strat == "no")
{
    std::cout << "The large man grows angry with you. \n";
    Sleep(0700);
    std::cout << "He unsheaths his heavy sword and swings it at you neck, killing you. \n";

    std::cout << "\n=== YOU DIED === \n";
    return 0;
}

if (strat == "yes")
{
if (sword == false && xbow == false)
{
    std::cout << "\nThe large man sees your lack of weapon and gros angry. \n";
    Sleep(0700);
    std::cout << "\nHe unsheaths his heavy sword and swings it at you neck, killing you. \n";

    std::cout << "=== YOU DIED === \n";
    return 0;    
} 
else 
{
    system("CLS");
    std::cout << "You prepare for battle!";
    Sleep(1200);

int a = guardFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, sword, Eyeball, fish, pitBlessing, xbow, spiderFriend, PitLantern);

if (a == 0)
{
    std::cout << "\n=== The Guard Drops his Sword! ===\n\n";
    std::cout << "It's a beautifully crafted sword sure to do damage!\n";
    collect = "";

while (collect != "yes" && collect != "no")
{
    std::cout << "\nWill you collect the Guards Sword? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
if (sword == true)
{    
    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "\nAre you sure you want to replace your Sword? (yes/no): ";

    std::cin >> collect;
if (collect == "yes")
{
    std::cout << "\n--- Guard Sword added to inventory ---\n\n";

    GuardSword = true;
    sword = false;

    std::cout << "\n___Inventory___ \n";

if (xbow == true) {std::cout << "    Crossbow    \n";};
if (sword == true) {std::cout << "    Sword    \n";};
if (fish == true){std::cout << "     Fish     \n";};
if (PitLantern == true){std::cout << "  Pit Lantern  \n";};
if (spiderFriend == true){std::cout << "__Companions__\n   Spider Friend";};
std::cout << endl;
}       
}

}

if (xbow == true)
{    
    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "\nAre you sure you want to replace your Crossbow? (yes/no) :";

    std::cin >> collect;
if (collect == "yes")
{
    std::cout << "\n--- Guard Sword added to inventory ---\n\n";

    GuardSword = true;
    xbow = false;

    std::cout << "\n___Inventory___ \n";

if (xbow == true) {std::cout << "    Crossbow    \n";};
if (sword == true) {std::cout << "    Sword    \n";};
if (fish == true){std::cout << "     Fish     \n";};
if (PitLantern == true){std::cout << "  Pit Lantern  \n";};
if (spiderFriend == true){std::cout << "__Companions__\n   Spider Friend";};
std::cout << endl;
}       
}

}
 
}

if (collect == "no")
{
    std::cout << "\n--- You leave the Guard Sword behind... ---\n\n";
}

    std::cout << "\n The huge metal door slides open. You hear a mumbled growling coming from inside...\n";
    std::cout << "For some reason you can that this is the end of the dungeon...\n\n";

    advance = "";
                
while (advance != "yes" && advance != "no")
{
    std::cout << "Will you advance? (yes/no): ";
    std::cin >> advance;

if (advance == "yes")
{
    std::cout << "\nYou advance into the dark purple lit room...\n";
    int a = dragonFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, sword, Eyeball, fish, pitBlessing, xbow, spiderFriend, PitLantern, GuardSword);

if (a == 0)
{
    return 0;
}
            
if (a == 1)
{
    std::cout << "\n\n=== YOU DIED ===\n";
    return 0;
}
}

if (advance == "no")
{
    std::cout << "\nThere seems to be no where else to go...\n";
    continue;
            }
        }
    }
} 

else if (a == 1)
{
    std::cout << "\n\n == YOU DIED ==";
    return 0;
                    }
                }
            }
        }
    }
}

if (advance == "no")
{
    std::cout << "\n Where else will you go?\n";
    continue;
                            }
                        }
                    }
                }
            }
        }
    }
}

// Left Side of Map below
if (advance == "left")
 {
    std::cout << "\n=== You find the Key in this room! === \n";

while (collect != "yes" || "no")
{
    Sleep(0700);
    std::cout << "Collect the Key? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
    std::cout << "\n";
    std::cout << "--- Key added to your inventory --- \n";
    key = true;

    std::cout << "___Inventory___ \n";

    if (bat == true) {std::cout << "    Bat \n";};
    if (key == true) {std::cout << "    Key \n";};
    if (fbpads == true){std::cout << "Football Pads \n";};
    if (wand == true){std::cout << "   Wand \n";};
    if (Eyeball == true){std::cout << "   Eyeball \n";};
        
    std::cout << "\n";
    advance = "";
}
if (collect == "no")
{
    std::cout << "\n";
    std::cout << "--- You left the Key behind... --- \n\n";
    advance = "";
}
            
while (advance != "right" && advance != "left")
{
    Sleep(0700);

    std::cout << "The path splits two ways. Which way will you go? (right/left): ";
    std::cin >> advance;

// DEATH BY ZOMBIE
if (advance == "right")
{

    std::cout << "\n You wander into a cold dark room. The door behind you slams shut. \n";
    Sleep(1000);
    std::cout << "~ A zombie appears in front of you! ~ \n";
    Sleep(1000);
    std::cout <<  "You try to run with all your might but are killed by the hands of the zombie... \n";
    std::cout << "\n\n === YOU DIED ===";
    health = 0;
    advance = "";
    return 0;
}

if (advance == "left")
{
    std::cout << "\n You wander upon a dirty bedroom, walls covered in gunk \n";
    Sleep(0700);
    std::cout << "\n=== In the corner you see a Baseball Bat! ===\n";
    Sleep(0700);

    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "Would you like to take the Bat? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
    std::cout << "\n--- Bat added to your inventory --- \n";
    bat = true;
    std::cout << "___Inventory___\n";
                     
if (bat == true) {std::cout << "    Bat \n";};
if (key == true) {std::cout << "    Key \n";};
if (fbpads == true){std::cout << "Football Pads \n";};
if (wand == true){std::cout << "   Wand \n";};
if (Eyeball == true){std::cout << "   Eyeball \n";};

    std::cout << "\n";

    advance = "";
}

if (collect == "no")
{
    std::cout << "--- You left the Bat behind... --- \n";
    bat = false;
                        
    advance = "";
}
while (advance != "right" && advance != "left")
{
    Sleep(0700);
    std::cout << "The paths ahead split two ways. Which will you go? (right/left): ";
    std::cin >> advance;

if (advance == "right")
{
    std::cout << "\n You wander into a familiar room. \n";
    Sleep(1000);
    std::cout << "It's a highschool locker room. Filled with footbal equipment. \n";
    Sleep(1000);
    std::cout << "\n === You see Football Pads on a shelf === \n";
    Sleep(0700);

    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "Will you take the Football Pads? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{

if (key == true)
{
    std::cout << "\n == The Football Pads == limit your inventory space and you can no longer hold == The Key == \n";
    Sleep(0700);

    collect = "";

while (collect != "yes" && collect != "no")
{
    std::cout << "\nWill you drop == the Key ==? \nThere is no way to get it back! (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
    std::cout << "\nYou strap on the == Football Pads == and leave == The Key == behind...\n\n";
    Sleep(1000);
    std::cout << "\n--- Football Pads added to inventory --- \n";
    fbpads = true;
    key = false;

} else if (collect == "no")
{
    std::cout << "\nYou keep == The Key == secure in your pocket and leave the == Football Pads == behind...\n\n";
    Sleep(1000);

    fbpads = false;
key = true;
        }
    }
}

else 
{
    std::cout << "\n--- Football Pads added to inventory --- \n";
    fbpads = true;
}

    std::cout << "___Inventory___\n";
                     
if (bat == true) {std::cout << "    Bat \n";};
if (key == true) {std::cout << "    Key \n";};
if (fbpads == true){std::cout << "Football Pads \n";};
if (wand == true){std::cout << "   Wand \n";};
if (Eyeball == true){std::cout << "   Eyeball \n";};
std::cout << endl;

}
if (collect == "no" )
{
    std::cout << "\n--- You leave the == Football Pads == behind... ---\n\n";
    Sleep(0700);

}
    Sleep(1000);

    std::cout << "There are two paths in front of you. The one ahead looks ominous...\n\n";
    advance = "";
    Sleep(0700);


while (advance != "left" && advance != "forward")
{
    std::cout << "Which way will you go? (left/forward): ";
    std::cin >> advance;

if (advance == "forward")
{
    std::cout << "\n You wander into the dark hallway... \n";
    Sleep(1200);
    std::cout << "The hallway gets hotter as you approach. \n";
    Sleep(1200);
    std::cout << "A huge metal door faded in from the dark infront of you. \n";
    Sleep(1200);

    std::cout << "\n === The door is locked but has a key hole === \n";
    Sleep(1000);


    advance = "";

if (key == false)
{
    std::cout << "\nYou have nothing to unlock the door with. Maybe == The Key == could've helped... \n";
    Sleep(1200);
    std::cout << "You start to head back. When you hear heavy steps ahead of you. \n";
    Sleep(1200);
    std::cout << "\n~ A huge man appears ahead of you ~ \n";
    Sleep(1200);
    std::cout << "\n=== He offers to open the door if you best him in 1 on 1 combat === \n";
    strat = "";

while (strat != "yes" && strat != "no")
{
    Sleep(1200);

    std::cout << "\nDo you accept his offer? (yes/no): ";
    std::cin >> strat;

if (strat == "no")
{
    std::cout << "The large man grows angry with you. \n";
    Sleep(0700);
    std::cout << "He unsheaths his heavy sword and swings it at you neck, killing you. \n";

    std::cout << "\n=== YOU DIED === \n";
    return 0;
}

if (strat == "yes")
{

if (bat == false)
{
    std::cout << "\nThe large man sees your lack of weapon and gros angry. \n";
    Sleep(0700);
    std::cout << "\nHe unsheaths his heavy sword and swings it at you neck, killing you. \n";

    std::cout << "=== YOU DIED === \n";
    return 0;    
} 
else 
{
    system("CLS");
    std::cout << "You prepare for battle!";
    Sleep(1200);

int a = guardFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, sword, Eyeball, fish, pitBlessing, xbow, spiderFriend, PitLantern);

if (a == 0)
{
    std::cout << "\n=== The Guard Drops his Sword! ===\n\n";
    std::cout << "It's a beautifully crafted sword sure to do damage!\n";
    collect = "";

while (collect != "yes" && collect != "no")
{
    std::cout << "\nWill you collect the Guards Sword? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{

if (bat == true)
{    
    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "\nAre you sure you want to replace your Bat? (yes/no) :";

    std::cin >> collect;
if (collect == "yes")
{
    std::cout << "\n--- Guard Sword added to inventory ---\n\n";

    GuardSword = true;
    bat = false;

    std::cout << "\n___Inventory___ \n";

if (bat == true) {std::cout << "    Bat \n";};
if (key == true) {std::cout << "    Key \n";};
if (fbpads == true){std::cout << "Football Pads \n";};
if (wand == true){std::cout << "   Wand \n";};
if (Eyeball == true){std::cout << "   Eyeball \n";};
std::cout << endl;
            }
        }
    }
}
if (collect == "no")
{
    std::cout << "\n--- You leave the Guard Sword behind... ---\n\n";
}

    std::cout << "\n The huge metal door slides open. You hear a mumbled growling coming from inside...\n";
    std::cout << "For some reason you can that this is the end of the dungeon...\n\n";

    advance = "";

while (advance != "yes" && advance != "no")
{
    std::cout << "Will you advance? (yes/no): ";
    std::cin >> advance;

if (advance == "yes")
{
    std::cout << "\nYou advance into the dark purple lit room...";
    int a = dragonFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, sword, Eyeball, fish, pitBlessing, xbow, spiderFriend, PitLantern, GuardSword);

if (a == 0)
{
    return 0;
}
            
if (a == 1)
{
    std::cout << "\n\n=== YOU DIED ===\n";
    return 0;
}
}

if (advance == "no")
{
    std::cout << "\nThere seems to be no where else to go...\n";
    continue;
            }
        }
    }
} 

else if (a == 1)
{
    std::cout << "\n\n == YOU DIED ==";
    return 0;
                }
            }
        }
    }
}
while (advance != "unlock" && advance != "leave")
{
    std::cout << "Will you unlock the door?(yes/no): ";
    std::cin >> advance;

if (advance == "yes")
{
    std::cout << "\n You push the key in with a click...\n";
    std::cout << "The door doesn't need to be pushed to open rather it opens on it's own.\n";
    std::cout << "The room is hot and lit purple. However it seems to be where you need to go.\n";

    advance = "";

while (advance != "yes" && advance != "no")
{
    std::cout << "Will you enter? (yes/no): ";
    std::cin >> advance;

if (advance == "yes")
{
    std::cout << "\nYou advance into the dark purple lit room...";
    int a = dragonFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, sword, Eyeball, fish, pitBlessing, xbow, spiderFriend, PitLantern, GuardSword);

if (a == 0)
{
    return 0;
}
            
if (a == 1)
{
    std::cout << "\n\n=== YOU DIED ===\n";
    return 0;
}
}
if (advance == "no")
{
    std::cout << "\nIt seems this is where you need to go...\n";
    continue;
        }
    }
}
if (advance == "no")
{
    std::cout << "\nWhat else is the key good for other than unlocking this door?\n";
    continue;
        }
    }
} 

if (advance == "left")
{
    std::cout << "\nYou wander into a large expansive room. \nA small man is in the corner cleaning a table that is under a constant leaking ceiling. \n";
    Sleep(1300);
    std::cout << "He turns to you...\n";
    Sleep(1000);
    std::cout << " \n???: You aren't supposed to be here...\n";
    
    advance = "";

while (advance != "A" && advance != "B" && advance != "C")
{
    std::cout << "(A) What? (B) Who are you? (C) What is this place?: ";
    std::cin >> advance; 

if (advance == "A")
{
    std::cout << "\n???: I said you aren't supposed to be here.\n";
}

if (advance == "B")
{
    std::cout << "\n ???: That doesn't matter. I've been here a long time...\n";
}

if (advance == "C")
{
    std::cout  << "\n???: Where sinners go to be sealed away...\n";
    }
}
    Sleep(1000);
    std::cout << "???: Since you're here and I've got infinite time, I'll give you a riddle! Answer correctly and you'll be rewarded!!\n";
    Sleep(1000);
    std::cout << "\n~ ???: Sound gooood? ~";

    advance = "";
while (advance != "yes" && advance != "no")
{
    std::cout << " (yes/no): ";            
    std::cin >> advance;

if (advance == "yes")
{
    int guesses = 4;

    std::cout << "\n ~ ???: Excellent! Here it is... \n\n";
    Sleep(0700);
while (guesses != 0)
{
    std::cout << "-----------------------------------------------------------------------------------------\n";
    std::cout << "???: It's a three-letter word that can cause a lot of strife...\n\n";
    Sleep(1200);
    std::cout << "???: It's not quite a crime but can ruin your life...\n\n";
    Sleep(1200);
    std::cout << "???: Some say it's a trap, others a test...\n\n";
    Sleep(1200);
    std::cout << "???: If you indulge in it you may never find rest...\n\n";
    std::cout << "-----------------------------------------------------------------------------------------\n";                
    Sleep(1200);

    advance = "";   

    std::cout << "What am I? (no caps): ";
    std::cin >> advance;
if (advance != "sin")
{
    guesses -= 1;
}

if (advance != "sin" && guesses == 3)
{
    std::cout << "\n???: Here's a hint: It something we can all do...\n\n";
    Sleep(1200);
    continue;
}
                
if (advance != "sin" && guesses == 2)
{
    std::cout << "\n???: Here's another hint: It can be small or large, intentional or unintentional...\n\n";
    Sleep(1200);
    continue;
}

if (advance != "sin" && guesses == 1)
{
    std::cout << "\n???: Last hint: It's associated with wrongdoing in religion...\n\n";
    Sleep(1200);
    continue;
}

if (guesses == 0)
{
    std::cout << "\n???: OOPS you're out of tries! The answer was == Sin == HAHAHAHA!\n\n";
}

if (advance == "sin")
{
    break;
    }
}

if (advance == "sin")
{
    std::cout << "\n???: Congrats! You got it right!! Wow!\n";
    Sleep(0700);
    std::cout << "\n???: The answer was == Sin ==!\n";
    Sleep(0700);
    std::cout << "\n He reaches into his pockets and pulls out a wooden stick...\n";
    Sleep(1000);
    std::cout << "\n???: I can't save you in every battle but wave this wand to heal you self 50 health and max stamina! It only has 2 uses per battle!\n";
    Sleep(1500);
    std::cout << "\n???: If you use it three times in one battle the wand breaks! Here take it!\n";
    Sleep(1500);
    std::cout << "\n--- Wand added to your inventory --- \n\n";
    std::cout << "___Inventory___\n";
                     
    wand = true;

if (bat == true) {std::cout << "    Bat \n";};
if (key == true) {std::cout << "    Key \n";};
if (fbpads == true){std::cout << "Football Pads \n";};
if (wand == true){std::cout << "   Wand \n";};
if (Eyeball == true){std::cout << "   Eyeball \n";};
                  
    }
}

if (advance == "no")
{
    std::cout << "\nThe little man giggles\n";
    std::cout << "\n???: Danger lurks ahead stranger. \n\n";
}

    std::cout << "\nThe little man runs off between your legs...\n";
    Sleep(0700);
    std::cout << "You can only go forward as you have already gone to see the Football Pads...\n\n";
    advance = "";

while (advance != "yes" && advance != "no")
{
    std::cout << "Will you advance?? (yes/no): ";
    std::cin >> advance;

if (advance == "yes")
{
    std::cout << "\nYou feel uneasy as you head down this hallway...\n";
    Sleep(0700);
    std::cout << "\n=== You see a freakly skinny and tall figure! ===\n";
    Sleep(0700);
    std::cout << "\nIt's ribs are stretching out farther than its arms probably can.\n";
    Sleep(1200);
    std::cout << "The thing crinckles and crunches into a ball and transforms into ";
    Sleep(0700);
    std::cout << ".";
    Sleep(0700);
    std::cout << ".";
    Sleep(0700);
    std::cout << ".";
    Sleep(0700);
    std::cout << " YOU!";
    Sleep(2100);
    system("CLS");
    int a = mimicsFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, Eyeball, fish, spiderFriend, PitLantern);
                 
if (a == 1)
{
    std::cout << "\n\n === YOU DIED ==";
    return 0;
}
if (a == 0)
{
    std::cout << "\nThe creature dropped a glass eyeball...\n";
    Sleep(0700);
    std::cout << "You pick up and drop it and drop it because of how slimy it is...\n";
    Sleep(0700);
    std::cout << "\nYour thumb bursts in blood...\n";
    Sleep(0700);
    std::cout << "\n=== The Eyeball seems to reflect damage ===\n";
                    
    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "Will you pick up the Eyeball? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
    std::cout << "\n--- EyeBall added to Inventory ---\n\n";
            
    Eyeball = true;
    std::cout << "___Inventory___\n";
                     
if (bat == true) {std::cout << "    Bat \n";};
if (key == true) {std::cout << "    Key \n";};
if (fbpads == true){std::cout << "Football Pads \n";};
if (wand == true){std::cout << "   Wand \n";};
if (Eyeball == true){std::cout << "   Eyeball \n";};
}
if (collect == "no")
{
    std::cout << "\n--- You leave the EyeBall behind... ---\n\n";
}

    std::cout << "\nThere is only one path in front of you... It looks very omnious...\n";
    advance = "";
    while (advance != "yes" && advance != "no")
{
    std::cout << "Will you go forward? (yes/no): ";
    std::cin >> advance;

if (advance == "yes")
{
    std::cout << "\n You wander into the dark hallway... \n";
    Sleep(1200);
    std::cout << "The hallway gets hotter as you approach. \n";
    Sleep(1200);
    std::cout << "A huge metal door faded in from the dark infront of you. \n";
    Sleep(1200);
    std::cout << "\n === The door is locked but has a key hole === \n";
    Sleep(1000);

    advance = "";
            
if (key == false)
{
    std::cout << "\nYou have nothing to unlock the door with. Maybe == The Key == could've helped... \n";
    Sleep(1200);
    std::cout << "You start to head back. When you hear heavy steps ahead of you. \n";
    Sleep(1200);
    std::cout << "\n~ A huge man appears ahead of you ~ \n";
    Sleep(1200);
    std::cout << "\n=== He offers to open the door if you best him in 1 on 1 combat === \n";
    strat = "";

while (strat != "yes" && strat != "no")
{
    Sleep(1200);
    std::cout << "\nDo you accept his offer? (yes/no): ";
    std::cin >> strat;

if (strat == "no")
{
    std::cout << "The large man grows angry with you. \n";
    Sleep(0700);
    std::cout << "He unsheaths his heavy sword and swings it at you neck, killing you. \n";
    std::cout << "\n=== YOU DIED === \n";
    return 0;
}

if (strat == "yes")
{
            
if (bat == false)
{
    std::cout << "\nThe large man sees your lack of weapon and gros angry. \n";
    Sleep(0700);
    std::cout << "\nHe unsheaths his heavy sword and swings it at you neck, killing you. \n";

    std::cout << "=== YOU DIED === \n";
    return 0;    
} 

    system("CLS");
    std::cout << "You prepare for battle!";
    Sleep(1200);

    int a = guardFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, sword, Eyeball, fish, pitBlessing, xbow, spiderFriend, PitLantern);

if (a == 0)
{
    std::cout << "\n=== The Guard Drops his Sword! ===\n\n";
    std::cout << "It's a beautifully crafted sword sure to do damage!\n";
    collect = "";

while (collect != "yes" && collect != "no")
{
    std::cout << "\nWill you collect the Guards Sword? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{

if (bat == true)
{    
    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "\nAre you sure you want to replace your Bat? (yes/no) :";

    std::cin >> collect;
if (collect == "yes")
{
    std::cout << "\n--- Guard Sword added to inventory ---\n\n";

    GuardSword = true;
    bat = false;

    std::cout << "\n___Inventory___ \n";

if (bat == true) {std::cout << "    Bat \n";};
if (key == true) {std::cout << "    Key \n";};
if (fbpads == true){std::cout << "Football Pads \n";};
if (wand == true){std::cout << "   Wand \n";};
if (Eyeball == true){std::cout << "   Eyeball \n";};
std::cout << endl;
            }
        }
    }

}

if (collect == "no")
{
    std::cout << "\n--- You leave the Guard Sword behind... ---\n\n";
}

    std::cout << "\nThe huge metal door slides open. You hear a mumbled growling coming from inside...\n";
    std::cout << "For some reason you can that this is the end of the dungeon...\n";

    advance = "";
                

while (advance != "yes" && advance != "no")
{
    std::cout << "Will you advance? (yes/no): ";
    std::cin >> advance;

if (advance == "yes")
{
    std::cout << "\nYou advance into the dark purple lit room...\n";
    int a = dragonFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, sword, Eyeball, fish, pitBlessing, xbow, spiderFriend, PitLantern, GuardSword);

if (a == 0)
{
    return 0;
}
            
if (a == 1)
{
    std::cout << "\n\n=== YOU DIED ===\n";
    return 0;
}
}

if (advance == "no")
{
    std::cout << "\nThere seems to be no where else to go...\n";
    continue;
            }
        }
    }
} 

else if (a == 1)
{
    std::cout << "\n\n == YOU DIED ==";
    return 0;
}
            }
        }
    }
}

if (advance == "no")
{
    std::cout << "It doesn't seem like you should go back...";
    continue;
                }
            }
        }
    }
}
if (advance == "no")
{
    std::cout << "\nYou must advance to continue!\n";
    continue;
}
                    }
                }
            }
        }
    }                                        
}

if (advance == "left")
{
    std::cout << "\nYou wander into a large expansive room. A small man is in the corner cleaning a table that is under a constant leaking ceiling. \n";
    Sleep(1000);
    std::cout << "He turns to you...\n";
    Sleep(0700);
    std::cout << " \n???: You aren't supposed to be here...\n";
    advance = "";

while (advance != "A" && advance != "B" && advance != "C")
{
    std::cout << "(A) What? (B) Who are you? (C) What is this place?: ";
    std::cin >> advance; 

if (advance == "A")
{
    std::cout << "\n???: I said you aren't supposed to be here.\n";
}

if (advance == "B")
{
    std::cout << "\n ???: That doesn't matter. I've been here a long time...\n";
}

if (advance == "C")
{
    std::cout  << "\n???: Where sinners go to be sealed away...\n";    
    }
}
    std::cout << "???: Since you're here and I've got infinite time, I'll give you a riddle! Answer correctly and you'll be rewarded!!\n";
    Sleep(1000);
    std::cout << "\n~ ???: Sound gooood? ~";

    advance = "";
while (advance != "yes" && advance != "no")
{
    std::cout << " (yes/no): ";            
    std::cin >> advance;

if (advance == "yes")
{
    int guesses = 4;

    std::cout << "\n ~ ???: Excellent! Here it is... \n\n";
    Sleep(0700);
while (guesses != 0)
{
    std::cout << "-----------------------------------------------------------------------------------------\n";
    std::cout << "???: It's a three-letter word that can cause a lot of strife...\n\n";
    Sleep(1200);
    std::cout << "???: It's not quite a crime but can ruin your life...\n\n";
    Sleep(1200);
    std::cout << "???: Some say it's a trap, others a test...\n\n";
    Sleep(1200);
    std::cout << "???: If you indulge in it you may never find rest...\n\n";
    std::cout << "-----------------------------------------------------------------------------------------\n";                
    Sleep(1200);

    advance = "";   

    std::cout << "What am I? (no caps): ";
    std::cin >> advance;
if (advance != "sin")
{
    guesses -= 1;
}

if (advance != "sin" && guesses == 3)
{
    std::cout << "\n???: Here's a hint: It something we can all do...\n\n";
    continue;
}

if (advance != "sin" && guesses == 2)
{
    std::cout << "\n???: Here's another hint: It can be small or large, intentional or unintentional...\n\n";
    continue;
}

if (advance != "sin" && guesses == 1)
{
    std::cout << "\n???: Last hint: It's associated with wrongdoing in religion...\n\n";
    continue;
}

if (guesses == 0)
{
    std::cout << "\n???: OOPS you're out of tries! The answer was == Sin == HAHAHAHA!\n\n";
}
if (advance == "sin")

{
    break;
}

            }

if (advance == "sin")
{
    std::cout << "\n???: Congrats! You got it right!! Wow!\n";
    Sleep(0700);
    std::cout << "\n???: The answer was == Sin ==!\n";
    Sleep(0700);
    std::cout << "\n He reaches into his pockets and pulls out a wooden stick...\n";
    Sleep(1000);
    std::cout << "\n???: I can't save you in every battle but wave this wand to heal you self 50 health and max stamina! It only has 2 uses per battle!\n";
    Sleep(1500);
    std::cout << "\n???:  If you use it three times in one battle the wand breaks! Here take it!\n";
    Sleep(1500);
    std::cout << "\n--- Wand added to your inventory --- \n\n";
    std::cout << "___Inventory___\n";
                     
    wand = true;

if (bat == true) {std::cout << "    Bat \n";};
if (key == true) {std::cout << "    Key \n";};
if (fbpads == true){std::cout << "Football Pads \n";};
if (wand == true){std::cout << "   Wand \n";};
if (Eyeball == true){std::cout << "   Eyeball \n";};              
    }        
}

if (advance == "no")
{
    std::cout << "\nThe little man giggles\n";
    std::cout << "\n???: Danger lurks ahead stranger. \n\n";
}

    std::cout << "\nThe little man runs off between your legs...\n";
    std::cout << "There are two directions in front of you. Left and Forward...\n\n";
advance = "";

while (advance != "left" && advance != "forward")
{
    std::cout << "Which way will you go? (left/forward): ";
    std::cin >> advance;

if (advance == "left")
{
    std::cout << "\nYou feel uneasy as you head down this hallway...\n";
    Sleep(0700);
    std::cout << "\n=== You see a freakly skinny and tall figure! ===\n";
    Sleep(0700);
    std::cout << "\nIt's ribs are stretching out farther than its arms probably can. Each rib Spread out freakishly.\n";
    Sleep(1200);
    std::cout << "The thing crinckles and crunches into a ball and transforms into ";
    Sleep(0700);
    std::cout << ".";
    Sleep(0700);
    std::cout << ".";
    Sleep(0700);
    std::cout << ".";
    Sleep(0700);
    std::cout << " YOU!";
    Sleep(1800);
    system("CLS");
    int a = mimicsFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, Eyeball, fish, spiderFriend, PitLantern);
                 
if (a == 1)
{
    std::cout << "\n\n === YOU DIED ==";
    return 0;
}
if (a == 0)
{
    std::cout << "\nThe creature dropped a glass eyeball...\n";
    Sleep(0700);
    std::cout << "You pick up and drop it and drop it because of how slimy it is...\n";
    Sleep(0700);
    std::cout << "\nYour thumb bursts in blood...\n";
    Sleep(0700);
    std::cout << "\n=== The Eyeball seems to reflect damage ===\n";
                    
    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "Will you pick up the Eyeball? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
    std::cout << "\n--- EyeBall added to Inventory ---\n\n";
            
    Eyeball = true;
    std::cout << "___Inventory___\n";
                     
if (bat == true) {std::cout << "    Bat \n";};
if (key == true) {std::cout << "    Key \n";};
if (fbpads == true){std::cout << "Football Pads \n";};
if (wand == true){std::cout << "   Wand \n";};
if (Eyeball == true){std::cout << "   Eyeball \n";};
}
if (collect == "no")
{
    std::cout << "\n--- You leave the EyeBall behind... ---\n\n";
}

    std::cout << "\nThere is only one path in front of you... It looks very omnious...\n";
    advance = "";
    while (advance != "yes" && advance != "no")
{
    std::cout << "Will you go forward? (yes/no): ";
    std::cin >> advance;

if (advance == "yes")
{
    std::cout << "\n You wander into the dark hallway... \n";
    Sleep(1200);
    std::cout << "The hallway gets hotter as you approach. \n";
    Sleep(1200);
    std::cout << "A huge metal door faded in from the dark infront of you. \n";
    Sleep(1200);
    std::cout << "\n === The door is locked but has a key hole === \n";
    Sleep(1000);


    advance = "";
            
if (key == false)
{
    std::cout << "\nYou have nothing to unlock the door with. Maybe == The Key == could've helped... \n";
    Sleep(1200);
    std::cout << "You start to head back. When you hear heavy steps ahead of you. \n";
    Sleep(1200);
    std::cout << "\n~ A huge man appears ahead of you ~ \n";
    Sleep(1200);
    std::cout << "\n=== He offers to open the door if you best him in 1 on 1 combat === \n";
    Sleep(1200);
    strat = "";

while (strat != "yes" && strat != "no")
{
    std::cout << "\nDo you accept his offer? (yes/no): ";
    std::cin >> strat;

if (strat == "no")
{
    std::cout << "The large man grows angry with you. \n";
    Sleep(0700);
    std::cout << "He unsheaths his heavy sword and swings it at you neck, killing you. \n";

    std::cout << "\n=== YOU DIED === \n";
    return 0;
}

if (strat == "yes")
{
            
if (bat == false)
{
    std::cout << "\nThe large man sees your lack of weapon and gros angry. \n";
    Sleep(0700);
    std::cout << "\nHe unsheaths his heavy sword and swings it at you neck, killing you. \n";

    std::cout << "=== YOU DIED === \n";
    return 0;    
} 

    system("CLS");
    std::cout << "You prepare for battle!";
    Sleep(1200);

    int a = guardFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, sword, Eyeball, fish, pitBlessing, xbow, spiderFriend, PitLantern);

if (a == 0)
{
    std::cout << "\n=== The Guard Drops his Sword! ===\n\n";
    std::cout << "It's a beautifully crafted sword sure to do damage!\n";
        collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "\nWill you collect the Guards Sword? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
if (bat == true)
{    
    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "\nAre you sure you want to replace your Bat? (yes/no) :";

    std::cin >> collect;
if (collect == "yes")
{
    std::cout << "\n--- Guard Sword added to inventory ---\n\n";

    GuardSword = true;
    bat = false;

    std::cout << "\n___Inventory___ \n";

if (bat == true) {std::cout << "    Bat \n";};
if (key == true) {std::cout << "    Key \n";};
if (fbpads == true){std::cout << "Football Pads \n";};
if (wand == true){std::cout << "   Wand \n";};
if (Eyeball == true){std::cout << "   Eyeball \n";};
    std::cout << endl;
            }
        }
    }
}

if (collect == "no")
{
    std::cout << "\n--- You leave the Guard Sword behind... ---\n\n";
}

    std::cout << "\nThe huge metal door slides open. You hear a mumbled growling coming from inside...\n";
    std::cout << "For some reason you can that this is the end of the dungeon...\n";

    advance = "";
                

while (advance != "yes" && advance != "no")
{
    std::cout << "Will you advance? (yes/no): ";
    std::cin >> advance;

if (advance == "yes")
{
    std::cout << "\nYou advance into the dark purple lit room...\n";
    int a = dragonFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, sword, Eyeball, fish, pitBlessing, xbow, spiderFriend, PitLantern, GuardSword);

if (a == 0)
{
    return 0;
}
            
if (a == 1)
{
    std::cout << "\n\n=== YOU DIED ===\n";
    return 0;
}
}

if (advance == "no")
{
    std::cout << "\nThere seems to be no where else to go...\n";
    continue;
}
    }
}

} else if (a == 1)
{
    std::cout << "\n\n == YOU DIED ==";
    return 0;
}
            }
        }
    }
}

if (advance == "no")
{
    std::cout << "It doesn't seem like you should go back...";
    continue;
}

}

        }
    }
}

if (advance == "forward")
{
std::cout << "\n You wander into a familiar room. \n";
    Sleep(1000);
    std::cout << "It's a highschool locker room. Filled with footbal equipment. \n";
    Sleep(1000);
    std::cout << "\n === You see Football Pads on a shelf === \n";
    Sleep(0700);

    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "Will you take the Football Pads? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{

if (key == true)
{
    std::cout << "\n == The Football Pads == limit your inventory space and you can no longer hold == The Key == \n";
    Sleep(0700);

    collect = "";

while (collect != "yes" && collect != "no")
{
    std::cout << "\nWill you drop == the Key ==? \nThere is no way to get it back! (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
    std::cout << "\nYou strap on the == Football Pads == and leave == The Key == behind...\n\n";
    Sleep(1000);
    std::cout << "\n--- Football Pads added to inventory --- \n";
    fbpads = true;
    key = false;
} else if (collect == "no")
{
    std::cout << "\nYou keep == The Key == secure in your pocket and leave the == Football Pads == behind...\n\n";
    Sleep(1000);

    fbpads = false;
    key = true;
}

}
} else 
{
    std::cout << "\n--- Football Pads added to inventory --- \n";
    fbpads = true;
}

    std::cout << "___Inventory___\n";
                     
if (bat == true) {std::cout << "    Bat \n";};
if (key == true) {std::cout << "    Key \n";};
if (fbpads == true){std::cout << "Football Pads \n";};
if (wand == true){std::cout << "   Wand \n";};
if (Eyeball == true){std::cout << "   Eyeball \n";};

    std::cout << "\n";
}
if (collect == "no" )
{
    std::cout << "\n--- You leave the == Football Pads == behind... ---\n\n";
    Sleep(0700);

}
    Sleep(1000);   
}

std::cout << "You've already been to see the little Riddle man so there is no point of going backwards.\n";
std::cout  << "\nThe only way to go is forward onto the omnious path ahead.\n\n";

advance = "";

while (advance != "yes" && advance != "no")
{
    std::cout <<  "Will you advance?(yes/no): ";
    std::cin >> advance;

if  (advance == "yes")
{
    std::cout << "\n You wander into the dark hallway... \n";
    Sleep(1200);
    std::cout << "The hallway gets hotter as you approach. \n";
    Sleep(1200);
    std::cout << "A huge metal door faded in from the dark infront of you. \n";
    Sleep(1200);

    std::cout << "\n === The door is locked but has a key hole === \n";
    Sleep(1000);


    advance = "";

if (key == false)
{
    std::cout << "\nYou have nothing to unlock the door with. Maybe == The Key == could've helped... \n";
    Sleep(1200);
    std::cout << "You start to head back. When you hear heavy steps ahead of you. \n";
    Sleep(1200);
    std::cout << "\n~ A huge man appears ahead of you ~ \n";
    Sleep(1200);
    std::cout << "\n=== He offers to open the door if you best him in 1 on 1 combat === \n";
    strat = "";

while (strat != "yes" && strat != "no")
{
    Sleep(1200);

    std::cout << "\nDo you accept his offer? (yes/no): ";
    std::cin >> strat;

if (strat == "no")
{
    std::cout << "The large man grows angry with you. \n";
    Sleep(0700);
    std::cout << "He unsheaths his heavy sword and swings it at you neck, killing you. \n";

    std::cout << "\n=== YOU DIED === \n";
    return 0;
}
if (strat == "yes")
{
if (bat == false)
{
    std::cout << "\nThe large man sees your lack of weapon and gros angry. \n";
    Sleep(0700);
    std::cout << "\nHe unsheaths his heavy sword and swings it at you neck, killing you. \n";

    std::cout << "=== YOU DIED === \n";
    return 0;  

} else 
{
    system("CLS");
    std::cout << "You prepare for battle!";
    Sleep(1200);

int a = guardFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, sword, Eyeball, fish, pitBlessing, xbow, spiderFriend, PitLantern);

if (a == 0)
{
    std::cout << "\n=== The Guard Drops his Sword! ===\n\n";
    std::cout << "It's a beautifully crafted sword sure to do damage!\n";
    collect = "";

while (collect != "yes" && collect != "no")
{
    std::cout << "\nWill you collect the Guards Sword? (yes/no): ";
    std::cin >> collect;

if (collect == "yes")
{
    if (bat == true)
{    
    collect = "";
while (collect != "yes" && collect != "no")
{
    std::cout << "\nAre you sure you want to replace your Bat? (yes/no) :";

    std::cin >> collect;
if (collect == "yes")
{
    std::cout << "\n--- Guard Sword added to inventory ---\n\n";

    GuardSword = true;
    bat = false;

    std::cout << "\n___Inventory___ \n";

if (bat == true) {std::cout << "    Bat \n";};
if (key == true) {std::cout << "    Key \n";};
if (fbpads == true){std::cout << "Football Pads \n";};
if (wand == true){std::cout << "   Wand \n";};
if (Eyeball == true){std::cout << "   Eyeball \n";};
    std::cout << endl;
            
            }
        }
    }
}

if (collect == "no")
{
    std::cout << "\n--- You leave the Guard Sword behind... ---\n\n";
}

    std::cout << "\n The huge metal door slides open. You hear a mumbled growling coming from inside...\n";
    std::cout << "For some reason you can that this is the end of the dungeon...\n\n";

    advance = "";

while (advance != "yes" && advance != "no")
{
    std::cout << "Will you advance? (yes/no): ";
    std::cin >> advance;

if (advance == "yes")
{
    std::cout << "\nYou advance into the dark purple lit room...";
    int a = dragonFight(health, attack, stamina, enemyHealth, enemyStamina, fbpads, wand, bat, sword, Eyeball, fish, pitBlessing, xbow, spiderFriend, PitLantern, GuardSword);

if (a == 0)
{
    return 0;
}
            
if (a == 1)
{
    std::cout << "\n\n=== YOU DIED ===\n";
    return 0;
}
}

if (advance == "no")
{
    std::cout << "\nThere seems to be no where else to go...\n";
    continue;
            }
        }
    }
} 

else if (a == 1)
{
    std::cout << "\n\n == YOU DIED ==";
    return 0;
}
            }
        }
    }
}

if (advance == "no")
{
    std::cout << "\nThere is no where else to go...\n";
    continue;
}
}

if (advance == "no")
{
    std::cout << "\nYou must advance to continue!\n";
    continue;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}