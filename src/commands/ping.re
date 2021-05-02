open CommandRegister;
let register = () => {
    name: ["ping", "pingar"],
    run: (message, client) => Discord.Message.reply(message, string_of_int(client.ws.ping))
};