#include "saftbus.h"
#include "core.h"
#include <iostream>

namespace saftbus
{

	const int N_CONNECTIONS = 32;

	SlotBusAcquired   bus_acquired;
	SlotNameAcquired  name_acquired;
	SlotNameAppeared  name_appeared;
	SlotNameLost      name_lost;
	SlotNameVanished  name_vanished;
	std::shared_ptr<Connection> connection;


	guint own_name (BusType bus_type, const std::string& name, const SlotBusAcquired& bus_acquired_slot, const SlotNameAcquired& name_acquired_slot, const SlotNameLost& name_lost_slot)//, BusNameOwnerFlags flags=Gio::DBus::BUS_NAME_OWNER_FLAGS_NONE)
	{
		init();
		if (_debug_level > 5) std::cerr << "own_name("<< bus_type<< "," << name <<") called" << std::endl;
		bus_acquired  = bus_acquired_slot;
		name_acquired = name_acquired_slot;
		name_lost     = name_lost_slot;

		// the connection object will be created here, and here should be decided 
		// if this will be a Connection on the server side or the proxy side
		// Saftbus is a one-to-many IPC, while DBus is a many-to-many IPC
		// The Saftbus daemon can run inside the server side Connection Object.
		connection = std::shared_ptr<Connection>(new Connection);

		bus_acquired(connection, "blub bus bus_acquired");
		name_acquired(connection, "blub name acquired");
		//name_lost(connection, "blub name lost");
		return 0;
	}

	void unown_name(guint id)
	{
		if (_debug_level > 5) std::cerr << "unown_name() called" << std::endl;

	}


	// bool deserialize(Glib::Variant<std::vector<Glib::VariantBase> > &result, const char *data, gsize size)
	// {
	// 	GVariant *grestored = g_variant_new_from_data(((const GVariantType *) "av"),
	// 												  (gconstpointer) data,  size, false,
	// 												  nullptr, nullptr);
	// 	bool normal_form = g_variant_is_normal_form(grestored);
	// 	if (_debug_level > 3) std::cerr << "deserialize() recieve variant has normal form? => " << normal_form << std::endl;
	// 	result = Glib::Variant<std::vector<Glib::VariantBase> >(grestored);
	// 	return true;
	// }



}
