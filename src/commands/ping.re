open CommandRegister
let register = () => {
  name: ["ping", "pingar"],
  description: "ping",
  run: (message, client) =>
    Discord.Message.reply(message, Discord.Str(string_of_int(client.ws.ping)))
}
