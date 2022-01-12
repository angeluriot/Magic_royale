#include "players/Player.hpp"

Player::Player(): m_name(""), m_health(20), m_alive(true) {}

std::string Player::get_name() const
{
	return m_name;
}

void Player::set_name(const std::string& name)
{
	m_name = name;
}

int Player::get_health() const
{
	return m_health;
}

void Player::set_health(int health)
{
	m_health = health;
}

void Player::reduce_health(int amount)
{
	m_health -= amount;

	if (m_health <= 0)
		m_alive = false;
}

std::map<Card::Color, int> Player::get_resources()
{
    std::map<Card::Color, int> res =
    {
		{ Card::Color::Colorless, 0 },
		{ Card::Color::White,     0 },
        { Card::Color::Blue,      0 },
        { Card::Color::Black,     0 },
        { Card::Color::Red,       0 },
        { Card::Color::Green,     0 }
	};

    for (Land land : m_lands)
    {
        if (!land.is_engaged())
        {
            res[Card::Color::Colorless] += 1;
            res[land.get_color()] += 1;
        }
    }
}

void Player::create_deck()
{
	// TODO
}

void Player::play_card(const Card& card)
{
    m_hand.remove(card);

    if (card.get_type() == Card::Type::Creature)
    {
        // m_creatures.add(card);
        m_creatures[m_creatures.size()].spawn();
        // TODO : désengager le nombre de terrains nécessaire
    }
    
    else
    {
        // m_lands.add(card);
    }

    // TODO : set_player()
}

bool Player::is_creature_playable(const Creature& creature)
{
    Card::Cost cost_map = creature.get_cost();
    std::map<Card::Color, int> resources_map = get_resources();
    std::map<Card::Color, int> to_engage =
    {
		{ Card::Color::Colorless, 0 },
		{ Card::Color::White,     0 },
        { Card::Color::Blue,      0 },
        { Card::Color::Black,     0 },
        { Card::Color::Red,       0 },
        { Card::Color::Green,     0 }
	};

    for (auto& [color, cost] : cost_map)
    {
        if (!(color == Card::Color::Colorless) && cost > 0)
        {
            if (cost > resources_map[color])
                return false;
            else
            {
                resources_map[color] -= cost;
                resources_map[Card::Color::Colorless] -= cost;
                to_engage[color] += cost;
            }
        }
    }
    
    if (cost_map[Card::Color::Colorless] > resources_map[Card::Color::Colorless])
        return false
    else
    {
        resources_map[Card::Color::Colorless] -= cost_map[Card::Color::Colorless];
        to_engage[Card::Color::Colorless] += cost_map[Card::Color::Colorless];
    }
    
    int number;
    
    while (to_engage[Card::Color::Colorless] > 0)
    {
        // TODO : afficher uniquement si le nb de terrains est > 0 et avec la bonne orthographe si = 1
        std::cout << "Choisissez un terrain a engager." << std::endl;
        std::cout << "Vous devez encore engager " << to_engange[Card::Color::White] << " terrains blancs, ";
        std::cout << to_engange[Card::Color::Blue] << " terrains bleus, ";
        std::cout << to_engange[Card::Color::Black] << " terrains noirs, ";
        std::cout << to_engange[Card::Color::Red] << " terrains rouges, ";
        std::cout << to_engange[Card::Color::Green] << " terrains verts et ";
        std::cout << to_engange[Card::Color::Colorless] << " autres terrains de n'importe quelle couleur." << std::endl;

        // TODO : afficher les numeros correspondant aux terrains que l'on peut engager
        std::cin >> number;
        
    }

    return true;
}

void Player::draw_card()
{
	// m_hand.add(m_library[m_library.size()]);
    m_library.remove(m_library.size());
    disengage_cards();
    // TODO : si plus de cartes à piocher, le joueur perd la partie
    // TODO : si déjà 7 cartes en main, défausser la carte (-> cimetière)
}

void Player::disengage_cards()
{
	for (Creature& creature : m_creatures)
    {
        if (creature.is_engaged())
            creature.disengage();
    }

    for (Land& land : m_lands)
    {
        if (land.is_engaged())
            land.disengage();
    }

    main_phase();
}

void Player::main_phase()
{
	bool stop = false;
    size_t number;
    while (!stop)
    {
        std::cout << "Phase principale" << std::endl;
        std::cout << "Veuillez selectionner une carte que vous voulez jouer en entrant son numero." << std::endl;
        std::cout << "Si vous avez fini de placer des cartes, tapez 0." << std::endl;
        std::cin >> number;
        if (number == 0)
            stop = true;
        else
        {
            if (number > m_hand.size())
                std::cout << "Vous avez entre un numero invalide." << std::endl;
            else
            {
                if (m_hand[number].get_type() == Card::Type::Creature)
                {
                    Creature* creature = (Creature*)&m_hand[number];
                    if (!is_creature_playable(*creature))
                        std::cout << "Vous n'avez pas suffisamment de terrains pour jouer cette carte." << std::endl;
                }
                else
                    play_card(m_hand[number]);
            }
        }
    }
}

void Player::combat_phase()
{
	// TODO
}

void Player::secondary_phase()
{
	// TODO
}

void Player::play()
{
	// TODO
}
