open CommandRegister
open DiscordButtons
let register = () => {
  name: ["botao"],
  description: "botao",
  run: (message, client) =>
    Discord.Message.reply(message, Discord.toOptions({
        embed: None,
        content: Some("Clique no botao"),
        buttons: Some([|{
            messageButton()
            -> Discord.Button.setLabel("Click me")
            -> Discord.Button.setStyle("red")
            -> Discord.Button.setID("TEST")
        }|])
    }))
}
