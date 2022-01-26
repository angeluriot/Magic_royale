#include <iostream>
#include <string>
#include "cards/Card.hpp"
#include "renderer/print.hpp"
#include "utils/utils.hpp"
#include "Game.hpp"

#include "cards/creatures/blacks/Balloon.hpp"
#include "cards/creatures/blacks/Bats.hpp"
#include "cards/creatures/blacks/Bomber.hpp"
#include "cards/creatures/blacks/DarkPrince.hpp"
#include "cards/creatures/blacks/Guards.hpp"
#include "cards/creatures/blacks/GiantSkeleton.hpp"
#include "cards/creatures/blacks/MegaKnight.hpp"
#include "cards/creatures/blacks/MiniPekka.hpp"
#include "cards/creatures/blacks/Pekka.hpp"
#include "cards/creatures/blacks/RoyalGhost.hpp"
#include "cards/creatures/blacks/SkeletonArmy.hpp"
#include "cards/creatures/blacks/SkeletonDragons.hpp"
#include "cards/creatures/blacks/Skeletons.hpp"
#include "cards/creatures/blacks/WallBreakers.hpp"

#include "cards/creatures/blues/ElectroDragon.hpp"
#include "cards/creatures/blues/ElectroSpirit.hpp"
#include "cards/creatures/blues/ElectroWizard.hpp"
#include "cards/creatures/blues/IceSpirit.hpp"
#include "cards/creatures/blues/IceWizard.hpp"
#include "cards/creatures/blues/MegaMinion.hpp"
#include "cards/creatures/blues/MinionHorde.hpp"
#include "cards/creatures/blues/Minions.hpp"
#include "cards/creatures/blues/NightWitch.hpp"
#include "cards/creatures/blues/MotherWitch.hpp"
#include "cards/creatures/blues/Sparky.hpp"
#include "cards/creatures/blues/Witch.hpp"
#include "cards/creatures/blues/Wizard.hpp"
#include "cards/creatures/blues/Zappies.hpp"

#include "cards/creatures/greens/DartGoblin.hpp"
#include "cards/creatures/greens/ElectroGiant.hpp"
#include "cards/creatures/greens/ElixirGolem.hpp"
#include "cards/creatures/greens/IceGolem.hpp"
#include "cards/creatures/greens/Giant.hpp"
#include "cards/creatures/greens/Golem.hpp"
#include "cards/creatures/greens/HogRider.hpp"
#include "cards/creatures/greens/RamRider.hpp"
#include "cards/creatures/greens/RoyalGiant.hpp"
#include "cards/creatures/greens/RoyalHogs.hpp"

#include "cards/creatures/reds/BabyDragon.hpp"
#include "cards/creatures/reds/InfernoDragon.hpp"
#include "cards/creatures/reds/Bowler.hpp"
#include "cards/creatures/reds/Firecracker.hpp"
#include "cards/creatures/reds/FireSpirit.hpp"
#include "cards/creatures/reds/GoblinBarrel.hpp"
#include "cards/creatures/reds/GoblinGang.hpp"
#include "cards/creatures/reds/GoblinGiant.hpp"
#include "cards/creatures/reds/Goblins.hpp"
#include "cards/creatures/reds/LavaHound.hpp"
#include "cards/creatures/reds/SpearGoblins.hpp"

#include "cards/creatures/whites/Archers.hpp"
#include "cards/creatures/whites/Bandit.hpp"
#include "cards/creatures/whites/BarbarianBarrel.hpp"
#include "cards/creatures/whites/Barbarians.hpp"
#include "cards/creatures/whites/BattleHealer.hpp"
#include "cards/creatures/whites/BattleRam.hpp"
#include "cards/creatures/whites/BattleRam.hpp"
#include "cards/creatures/whites/CannonCart.hpp"
#include "cards/creatures/whites/EliteBarbarians.hpp"
#include "cards/creatures/whites/Executioner.hpp"
#include "cards/creatures/whites/Fisherman.hpp"
#include "cards/creatures/whites/FlyingMachine.hpp"
#include "cards/creatures/whites/Hunter.hpp"
#include "cards/creatures/whites/Knight.hpp"
#include "cards/creatures/whites/Lumberjack.hpp"
#include "cards/creatures/whites/MagicArcher.hpp"
#include "cards/creatures/whites/Miner.hpp"
#include "cards/creatures/whites/Musketeer.hpp"
#include "cards/creatures/whites/Prince.hpp"
#include "cards/creatures/whites/Princess.hpp"
#include "cards/creatures/whites/Rascals.hpp"
#include "cards/creatures/whites/RoyalRecruits.hpp"
#include "cards/creatures/whites/ThreeMusketeers.hpp"
#include "cards/creatures/whites/Valkyrie.hpp"

#include "cards/lands/Forest.hpp"
#include "cards/lands/Island.hpp"
#include "cards/lands/Mountain.hpp"
#include "cards/lands/Plain.hpp"
#include "cards/lands/Swamp.hpp"

#include "cards/spells/Lightning.hpp"
#include "cards/spells/Rocket.hpp"
#include "cards/spells/Graveyard.hpp"
#include "cards/spells/Freeze.hpp"
#include "cards/spells/Poison.hpp"
#include "cards/spells/Fireball.hpp"
#include "cards/spells/Arrows.hpp"
#include "cards/spells/Tornado.hpp"
#include "cards/spells/Clone.hpp"
#include "cards/spells/Mirror.hpp"
#include "cards/spells/Earthquake.hpp"
#include "cards/spells/Zap.hpp"
#include "cards/spells/GiantSnowball.hpp"
#include "cards/spells/Rage.hpp"
#include "cards/spells/TheLog.hpp"
#include "cards/spells/HealSpirit.hpp"

PtrList<Card> get_all_card()
{
	PtrList<Card> cards;

	cards.add(Balloon());
	cards.add(Bats());
	cards.add(Bomber());
	cards.add(DarkPrince());
	cards.add(GiantSkeleton());
	cards.add(Guards());
	cards.add(MegaKnight());
	cards.add(MiniPekka());
	cards.add(Pekka());
	cards.add(RoyalGhost());
	cards.add(SkeletonArmy());
	cards.add(SkeletonDragons());
	cards.add(Skeletons());
	cards.add(WallBreakers());

	cards.add(ElectroDragon());
	cards.add(ElectroSpirit());
	cards.add(ElectroWizard());
	cards.add(IceSpirit());
	cards.add(IceWizard());
	cards.add(MegaMinion());
	cards.add(MinionHorde());
	cards.add(Minions());
	cards.add(NightWitch());
	cards.add(MotherWitch());
	cards.add(Sparky());
	cards.add(Witch());
	cards.add(Wizard());
	cards.add(Zappies());

	cards.add(DartGoblin());
	cards.add(ElectroGiant());
	cards.add(ElixirGolem());
	cards.add(IceGolem());
	cards.add(Giant());
	cards.add(Golem());
	cards.add(HogRider());
	cards.add(RamRider());
	cards.add(RoyalGiant());
	cards.add(RoyalHogs());

	cards.add(BabyDragon());
	cards.add(InfernoDragon());
	cards.add(Bowler());
	cards.add(Firecracker());
	cards.add(FireSpirit());
	cards.add(GoblinBarrel());
	cards.add(GoblinGang());
	cards.add(GoblinGiant());
	cards.add(Goblins());
	cards.add(LavaHound());
	cards.add(SpearGoblins());

	cards.add(Archers());
	cards.add(Bandit());
	cards.add(BarbarianBarrel());
	cards.add(Barbarians());
	cards.add(BattleHealer());
	cards.add(BattleRam());
	cards.add(CannonCart());
	cards.add(EliteBarbarians());
	cards.add(Executioner());
	cards.add(Fisherman());
	cards.add(FlyingMachine());
	cards.add(Hunter());
	cards.add(Knight());
	cards.add(Lumberjack());
	cards.add(MagicArcher());
	cards.add(Miner());
	cards.add(Musketeer());
	cards.add(Prince());
	cards.add(Princess());
	cards.add(Rascals());
	cards.add(RoyalRecruits());
	cards.add(ThreeMusketeers());
	cards.add(Valkyrie());

	cards.add(Forest());
	cards.add(Island());
	cards.add(Mountain());
	cards.add(Plain());
	cards.add(Swamp());

	cards.add(Lightning());
	cards.add(Rocket());
	cards.add(Graveyard());
	cards.add(Freeze());
	cards.add(Poison());
	cards.add(Fireball());
	cards.add(Arrows());
	cards.add(Tornado());
	cards.add(Clone());
	cards.add(Mirror());
	cards.add(Earthquake());
	cards.add(Zap());
	cards.add(GiantSnowball());
	cards.add(Rage());
	cards.add(TheLog());
	cards.add(HealSpirit());

	return cards;
}

PtrList<Card> Card::all_cards = get_all_card();

PtrList<Card> Card::get_cards_from_string(const std::vector<std::string>& cards_string)
{
	// Throw error for deck with > 30 cards
	if ((int)cards_string.size() > Game::deck_size)
		throw_error("A deck can't have more than " + to_str(Game::deck_size) + " cards, please remove " +
			(cards_string.size() - Game::deck_size > 1 ? to_str(cards_string.size() - Game::deck_size) + " cards." : "a card."));

	// Throw error for deck with < 30 cards
	if ((int)cards_string.size() < Game::deck_size)
		throw_error("A deck can't have less than " + to_str(Game::deck_size) + " cards, please add " +
			(Game::deck_size - cards_string.size() > 1 ? to_str(Game::deck_size - cards_string.size()) + " cards." : "a card."));

	PtrList<Card> cards;

	// Throw error for deck with duplicates
	for (auto& card_string : cards_string)
		for (int i = 0; i < (int)all_cards.size(); i++)
		{
			if (card_string == all_cards[i].get_name())
			{
				if (all_cards[i].get_type() != Type::Land)
					for (auto& card : cards)
						if (card.get_name() == all_cards[i].get_name())
							throw_error("A deck can't have multiple copies of the same card (except for lands), please replace the extra copies of " +
								to_str(italic) + all_cards[i].get_name() + to_str(no_italic) + " by other unique cards.");

				cards.add(all_cards[i]);

				break;
			}

			if (i == (int)all_cards.size() - 1)
				throw_error("Card not found: \"" + to_str(italic) + card_string + to_str(no_italic) + "\".");
		}

	return cards;
}

Card::Card(): m_owner(nullptr), m_engaged(false) {}

Card::~Card() {}

void Card::set_owner(Player& player)
{
	m_owner = &player;
}

void Card::engage()
{
	m_engaged = true;
}

void Card::disengage()
{
	m_engaged = false;
}

bool Card::is_engaged() const
{
	return m_engaged;
}

void Card::reset()
{
	disengage();
}

void Card::print() const
{
	std::cout << bold << "Name: " << ::reset << ::get_color(get_color()) << get_name() << End(1);

	if (!get_cost().empty())
	{
		std::cout << bold << "Cost: " << End();

		for (auto& [color, cost] : get_cost())
		{
			if (color == Color::Colorless)
				std::cout << cost << End();

			else
			{
				std::cout << " " << End();

				for (int i = 0; i < cost; i++)
					std::cout << ::get_color(color) << "*" << End();
			}
		}

		std::cout << End(1);
	}

	std::cout << bold << "Type: " << ::reset << ::get_color(get_color()) << get_full_type() << End(1);
}
