package pokedex;

public enum PokedexCertificate {
	REGIONAL_COMPLETE,
	NATIONAL_COMPLETE,
	#ifdef SANGO
	AGB_TRANSFERRED
	#endif
}