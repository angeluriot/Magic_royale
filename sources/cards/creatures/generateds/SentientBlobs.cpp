#include "cards/creatures/generateds/SentientBlobs.hpp"
#include "players/Player.hpp"
#include "renderer/print.hpp"
#include "cards/lands/Forest.hpp"

SentientBlobs::SentientBlobs(): Creature(get_full_power(), get_full_toughness(), get_capacities()) {}

SentientBlobs::~SentientBlobs() {}

std::string SentientBlobs::get_full_type() const
{
	return Creature::get_full_type() + " - Golem";
}

Card::Color SentientBlobs::get_color() const
{
	return Color::Green;
}

std::string SentientBlobs::get_name() const
{
	return "Sentient Blobs";
}

std::vector<Creature::Capacity> SentientBlobs::get_capacities() const
{
	return
	{
		Capacity::Unblockable
	};
}

std::string SentientBlobs::get_description() const
{
	return Creature::get_description() + "Gives 2 Forest cards to the opponent on death.";
}

Card::Cost SentientBlobs::get_cost() const
{
	return {};
}

int SentientBlobs::get_full_power() const
{
	return 1;
}

int SentientBlobs::get_full_toughness() const
{
	return 2;
}

void SentientBlobs::die()
{
	Creature::die();

	std::cout << cyan << "[INFO] " << ::reset << bold << magenta << m_owner->get_opponent().get_name() << ::reset << " got 2 " <<
		italic << ::get_color(Forest().get_color()) << Forest().get_name() << ::reset << " cards."  << End(2);

	m_owner->get_opponent().lands.add(Forest());
	m_owner->get_opponent().lands.add(Forest());
}

Card* SentientBlobs::clone() const
{
	return new SentientBlobs(*this);
}
