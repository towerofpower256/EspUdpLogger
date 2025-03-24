# Listen for UDP messages and output them to the console
#
# A little clunky, needs restarting sometimes, but works OK.
#
# Source: https://stackoverflow.com/questions/12148666/send-and-receive-data-via-udp-in-powershell

$port = 12345
$endpoint = New-Object System.Net.IPEndPoint ([IPAddress]::Any, $port)
Try {
    while($true) {
        $socket = New-Object System.Net.Sockets.UdpClient $port
        $content = $socket.Receive([ref]$endpoint)
        $socket.Close()
        [Text.Encoding]::ASCII.GetString($content)
    }
} Catch {
    "$($Error[0])"
}