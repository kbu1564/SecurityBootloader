/* hello.c - test module for dynamic loading */
/*
 *  GRUB  --  GRand Unified Bootloader
 *  Copyright (C) 2003,2007  Free Software Foundation, Inc.
 *  Copyright (C) 2003  NIIBE Yutaka <gniibe@m17n.org>
 *
 *  GRUB is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  GRUB is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GRUB.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <grub/net.h>
#include <grub/net/arp.h>
#include <grub/net/tcp.h>
#include <grub/net/ip.h>
#include <grub/net/ethernet.h>
#include <grub/net/netbuff.h>
#include <grub/time.h>
#include <grub/file.h>
#include <grub/i18n.h>
#include <grub/mm.h>
#include <grub/misc.h>
#include <grub/dl.h>
#include <grub/command.h>
#include <grub/env.h>
#include <grub/loader.h>
#include <grub/bufio.h>
#include <grub/kernel.h>

#include <grub/types.h>
#include <grub/err.h>
#include <grub/extcmd.h>
#include <grub/i18n.h>

GRUB_MOD_LICENSE ("GPLv3+");

static grub_err_t
hello_tcp_receive (grub_net_tcp_socket_t sock __attribute__ ((unused)), struct grub_net_buff *nb, void *f __attribute__ ((unused)))
{
  grub_err_t err;

  if (!sock)
  {
      grub_netbuff_free(nb);
      return GRUB_ERR_NONE;
  }

  return err;
}

static void
hello_tcp_err (grub_net_tcp_socket_t sock __attribute__ ((unused)), void *f __attribute__ ((unused)))
{
}

static grub_err_t
grub_cmd_hello (grub_extcmd_context_t ctxt __attribute__ ((unused)),
		int argc __attribute__ ((unused)),
		char **args __attribute__ ((unused)))
{
  grub_printf ("%s\n", _("Send Network Packet Test"));

  char server[100];
  grub_strcpy(server, "119.205.252.21");

  grub_net_tcp_socket_t sock = grub_net_tcp_open(server, 10880, hello_tcp_receive, hello_tcp_err, hello_tcp_err, 0);

  grub_err_t err;
  struct grub_net_buff *nb = grub_netbuff_alloc(GRUB_NET_TCP_RESERVE_SIZE + grub_strlen("grub -> server test") + 1);
  if (nb)
  {
      grub_netbuff_reserve(nb, GRUB_NET_TCP_RESERVE_SIZE);
      grub_uint8_t *ptr = nb->tail;
      err = grub_netbuff_put(nb, grub_strlen("grub -> server test") + 1);
      if (err)
      {
          grub_netbuff_free(nb);
          grub_net_tcp_close(sock, GRUB_NET_TCP_ABORT);
          return err;
      }
      grub_memcpy(ptr, "grub -> server test", grub_strlen("grub -> server test") + 1);
  }
  err = grub_net_send_tcp_packet(sock, nb, 1);
  grub_net_tcp_close(sock, GRUB_NET_TCP_ABORT);

  return 0;
}

static grub_extcmd_t cmd;

GRUB_MOD_INIT(hello)
{
  cmd = grub_register_extcmd ("hello", grub_cmd_hello, 0, 0, N_("Extension Network Test Command!"), 0);
}

GRUB_MOD_FINI(hello)
{
  grub_unregister_extcmd (cmd);
}
