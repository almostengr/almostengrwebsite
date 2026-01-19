using Almostengr.AlmostengrWebsite.Common.GardeningData.DomainServices.Interfaces;
using Almostengr.AlmostengrWebsite.Common.GardeningData.DomainServices;
using System.Net.Http;
using System.Threading.Tasks;
using Almostengr.AlmostengrWebsite.Common.Common.Infrastructure.Interfaces;
using Almostengr.AlmostengrWebsite.Common.Common.Infrastructure;

namespace Almostengr.AlmostengrWebsite.GardenWeather;

class Program
{
    static async Task<int> Main(string[] args)
    {
        HttpClient httpClient = new();
        IAeJson aeJson = new AeJson(httpClient);
        IAddDataToFileService addDataToFileService = new AddDataToFileService(aeJson);
        int returnCode = await addDataToFileService.ExecuteAsync();
        return returnCode;
    }
}
