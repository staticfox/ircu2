/* Include guard intentionally absent.  This file will normally be
 * included multiple times by ircd_features.c, with different
 * definitions for the following macros:
 * F_I(NAME, FLAGS, DEFAULT, NOTIFY)
 * F_U(NAME, FLAGS, DEFAULT, NOTIFY)
 * F_B(NAME, FLAGS, DEFAULT, NOTIFY)
 * F_S(NAME, FLAGS, DEFAULT, NOTIFY)
 * F_A(NAME, REAL_NAME)
 *
 * F_I() is used for features that take signed integer values.
 * F_U() is used for features that take unsigned integer values.
 * F_B() is used for features that take Boolean (true/false) values.
 * F_S() is used for features that take string values.
 * F_A() is used for features that are aliases for other features.
 *
 * NAME and REAL_NAME have no prefixes.
 * DEFAULT is an integer or (for F_S()) string literal.
 * NOTIFY is a pointer to a function taking and returning void.
 */

  F_S(DOMAINNAME, 0, DOMAINNAME, 0)
  F_B(RELIABLE_CLOCK, 0, 0, 0)
  F_U(BUFFERPOOL, 0, 27000000, 0)
  F_B(HAS_FERGUSON_FLUSHER, 0, 0, 0)
  F_U(CLIENT_FLOOD, 0, 1024, 0)
  F_I(SERVER_PORT, FEAT_OPER, 4400, 0)
  F_B(NODEFAULTMOTD, 0, 1, 0)
  F_S(MOTD_BANNER, FEAT_NULL, 0, 0)
  F_S(PROVIDER, FEAT_NULL, 0, 0)
  F_B(KILL_IPMISMATCH, FEAT_OPER, 0, 0)
  F_B(IDLE_FROM_MSG, 0, 1, 0)
  F_B(HUB, 0, 0, feature_notify_hub)
  F_B(WALLOPS_OPER_ONLY, 0, 0, 0)
  F_B(NODNS, 0, 0, 0)
  F_B(NOIDENT, 0, 0, 0)
  F_S(DEFAULT_LIST_PARAM, FEAT_NULL, 0, list_set_default)
  F_U(NICKNAMEHISTORYLENGTH, 0, 800, whowas_realloc)
  F_B(HOST_HIDING, 0, 1, 0)
  F_S(HIDDEN_HOST, FEAT_CASE, "users.undernet.org", 0)
  F_S(HIDDEN_IP, 0, "127.0.0.1", 0)
  F_B(CONNEXIT_NOTICES, 0, 0, 0)
  F_B(OPLEVELS, 0, 1, set_isupport_chanmodes)
  F_B(ZANNELS, 0, 1, 0)
  F_B(LOCAL_CHANNELS, 0, 1, set_isupport_chantypes)
  F_B(TOPIC_BURST, 0, 0, 0)
  F_B(USER_GLIST, 0, 1, 0)
  F_B(DISABLE_GLINES, 0, 0, 0)

  /* features that probably should not be touched */
  F_I(KILLCHASETIMELIMIT, 0, 30, 0)
  F_U(MAXCHANNELSPERUSER, 0, 10, set_isupport_maxchannels)
  F_U(NICKLEN, 0, 12, set_isupport_nicklen)
  F_I(AVBANLEN, 0, 40, 0)
  F_I(MAXBANS, 0, 100, set_isupport_maxbans)
  F_I(MAXSILES, 0, 25, set_isupport_maxsiles)
  F_I(HANGONGOODLINK, 0, 300, 0)
  F_I(HANGONRETRYDELAY, 0, 10, 0)
  F_I(CONNECTTIMEOUT, 0, 90, 0)
  F_I(MAXIMUM_LINKS, 0, 1, init_class) /* reinit class 0 as needed */
  F_I(PINGFREQUENCY, 0, 120, init_class)
  F_I(CONNECTFREQUENCY, 0, 600, init_class)
  F_U(DEFAULTMAXSENDQLENGTH, 0, 40000, init_class)
  F_I(GLINEMAXUSERCOUNT, 0, 20, 0)
  F_I(SOCKSENDBUF, 0, SERVER_TCP_WINDOW, 0)
  F_I(SOCKRECVBUF, 0, SERVER_TCP_WINDOW, 0)
  F_I(IPCHECK_CLONE_LIMIT, 0, 4, 0)
  F_I(IPCHECK_CLONE_PERIOD, 0, 40, 0)
  F_I(IPCHECK_48_CLONE_LIMIT, 0, 50, 0)
  F_I(IPCHECK_48_CLONE_PERIOD, 0, 10, 0)
  F_I(IPCHECK_CLONE_DELAY, 0, 600, 0)
  F_U(CHANNELLEN, 0, 200, set_isupport_channellen)

  /* Some misc. default paths */
  F_S(MPATH, FEAT_CASE | FEAT_MYOPER, "ircd.motd", motd_init_local)
  F_S(RPATH, FEAT_CASE | FEAT_MYOPER, "remote.motd", motd_init_remote)
  F_S(PPATH, FEAT_CASE | FEAT_MYOPER | FEAT_READ, "ircd.pid", 0)

  /* Networking features */
  F_I(TOS_SERVER, 0, 0x08, 0)
  F_I(TOS_CLIENT, 0, 0x08, 0)
  F_I(POLLS_PER_LOOP, 0, 200, 0)
  F_I(IRCD_RES_RETRIES, 0, 2, 0)
  F_I(IRCD_RES_TIMEOUT, 0, 4, 0)
  F_I(AUTH_TIMEOUT, 0, 9, 0)
  F_B(ANNOUNCE_INVITES, 0, 0, 0)

  /* features that affect all operators */
  F_B(CONFIG_OPERCMDS, 0, 0, 0)

  /* HEAD_IN_SAND Features */
  F_B(HIS_SNOTICES, 0, 1, 0)
  F_B(HIS_SNOTICES_OPER_ONLY, 0, 1, 0)
  F_B(HIS_DEBUG_OPER_ONLY, 0, 1, 0)
  F_B(HIS_WALLOPS, 0, 1, 0)
  F_B(HIS_MAP, 0, 1, 0)
  F_B(HIS_LINKS, 0, 1, 0)
  F_B(HIS_TRACE, 0, 1, 0)
  F_A(HIS_STATS_a, HIS_STATS_NAMESERVERS)
  F_B(HIS_STATS_NAMESERVERS, 0, 1, 0)
  F_A(HIS_STATS_c, HIS_STATS_CONNECT)
  F_B(HIS_STATS_CONNECT, 0, 1, 0)
  F_A(HIS_STATS_d, HIS_STATS_CRULES)
  F_B(HIS_STATS_CRULES, 0, 1, 0)
  F_A(HIS_STATS_e, HIS_STATS_ENGINE)
  F_B(HIS_STATS_ENGINE, 0, 1, 0)
  F_A(HIS_STATS_f, HIS_STATS_FEATURES)
  F_B(HIS_STATS_FEATURES, 0, 1, 0)
  F_A(HIS_STATS_F, HIS_STATS_FEATURESALL)
  F_B(HIS_STATS_FEATURESALL, 0, 1, 0)
  F_A(HIS_STATS_g, HIS_STATS_GLINES)
  F_B(HIS_STATS_GLINES, 0, 1, 0)
  F_A(HIS_STATS_i, HIS_STATS_ACCESS)
  F_B(HIS_STATS_ACCESS, 0, 1, 0)
  F_A(HIS_STATS_j, HIS_STATS_HISTOGRAM)
  F_B(HIS_STATS_HISTOGRAM, 0, 1, 0)
  F_A(HIS_STATS_J, HIS_STATS_JUPES)
  F_B(HIS_STATS_JUPES, 0, 1, 0)
  F_A(HIS_STATS_k, HIS_STATS_KLINES)
  F_B(HIS_STATS_KLINES, 0, 1, 0)
  F_A(HIS_STATS_l, HIS_STATS_LINKS)
  F_B(HIS_STATS_LINKS, 0, 1, 0)
  F_A(HIS_STATS_L, HIS_STATS_MODULES)
  F_B(HIS_STATS_MODULES, 0, 1, 0)
  F_A(HIS_STATS_m, HIS_STATS_COMMANDS)
  F_B(HIS_STATS_COMMANDS, 0, 1, 0)
  F_A(HIS_STATS_o, HIS_STATS_OPERATORS)
  F_B(HIS_STATS_OPERATORS, 0, 1, 0)
  F_A(HIS_STATS_p, HIS_STATS_PORTS)
  F_B(HIS_STATS_PORTS, 0, 1, 0)
  F_A(HIS_STATS_q, HIS_STATS_QUARANTINES)
  F_B(HIS_STATS_QUARANTINES, 0, 1, 0)
  F_A(HIS_STATS_R, HIS_STATS_MAPPINGS)
  F_B(HIS_STATS_MAPPINGS, 0, 1, 0)
  F_A(HIS_STATS_r, HIS_STATS_USAGE)
  F_B(HIS_STATS_USAGE, 0, 1, 0)
  F_A(HIS_STATS_t, HIS_STATS_LOCALS)
  F_B(HIS_STATS_LOCALS, 0, 1, 0)
  F_A(HIS_STATS_T, HIS_STATS_MOTDS)
  F_B(HIS_STATS_MOTDS, 0, 1, 0)
  F_A(HIS_STATS_u, HIS_STATS_UPTIME)
  F_B(HIS_STATS_UPTIME, 0, 0, 0)
  F_A(HIS_STATS_U, HIS_STATS_UWORLD)
  F_B(HIS_STATS_UWORLD, 0, 1, 0)
  F_A(HIS_STATS_v, HIS_STATS_VSERVERS)
  F_B(HIS_STATS_VSERVERS, 0, 1, 0)
  F_A(HIS_STATS_w, HIS_STATS_USERLOAD)
  F_B(HIS_STATS_USERLOAD, 0, 0, 0)
  F_A(HIS_STATS_W, HIS_STATS_WEBIRC)
  F_B(HIS_STATS_WEBIRC, 0, 1, 0)
  F_A(HIS_STATS_x, HIS_STATS_MEMUSAGE)
  F_B(HIS_STATS_MEMUSAGE, 0, 1, 0)
  F_A(HIS_STATS_y, HIS_STATS_CLASSES)
  F_B(HIS_STATS_CLASSES, 0, 1, 0)
  F_A(HIS_STATS_z, HIS_STATS_MEMORY)
  F_B(HIS_STATS_MEMORY, 0, 1, 0)
  F_B(HIS_STATS_IAUTH, 0, 1, 0)
  F_B(HIS_WEBIRC, 0, 1, 0)
  F_B(HIS_WHOIS_SERVERNAME, 0, 1, 0)
  F_B(HIS_WHOIS_IDLETIME, 0, 1, 0)
  F_B(HIS_WHOIS_LOCALCHAN, 0, 1, 0)
  F_B(HIS_WHO_SERVERNAME, 0, 1, 0)
  F_B(HIS_WHO_HOPCOUNT, 0, 1, 0)
  F_B(HIS_MODEWHO, 0, 1, 0)
  F_B(HIS_BANWHO, 0, 1, 0)
  F_B(HIS_KILLWHO, 0, 1, 0)
  F_B(HIS_REWRITE, 0, 1, 0)
  F_I(HIS_REMOTE, 0, 1, 0)
  F_B(HIS_NETSPLIT, 0, 1, 0)
  F_S(HIS_SERVERNAME, 0, "*.undernet.org", feature_notify_servername)
  F_S(HIS_SERVERINFO, 0, "The Undernet Underworld", feature_notify_serverinfo)
  F_S(HIS_URLSERVERS, 0, "http://www.undernet.org/servers.php", 0)

  /* Misc. random stuff */
  F_S(NETWORK, 0, "UnderNet", set_isupport_network)
  F_S(URL_CLIENTS, 0, "ftp://ftp.undernet.org/pub/irc/clients", 0)
  F_S(URLREG, 0, "http://cservice.undernet.org/live/", 0)
  F_I(SPAM_OPER_COUNTDOWN, 0, 5, 0)
  F_I(SPAM_EXPIRE_TIME, 0, 120, 0)
  F_I(SPAM_JOINED_TIME, 0, 60, 0)
  F_I(SPAM_FJP_COUNT, 0, 5, 0)

  /* Really special features (tm) */
  F_B(NETWORK_REHASH, 0, 0, 0)
  F_B(NETWORK_RESTART, 0, 0, 0)
  F_B(NETWORK_DIE, 0, 0, 0)

#undef F_A
#undef F_S
#undef F_B
#undef F_U
#undef F_I