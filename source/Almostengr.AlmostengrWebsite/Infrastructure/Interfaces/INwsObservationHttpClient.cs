using Almostengr.AlmostengrWebsite.Common;

namespace Almostengr.AlmostengrWebsite.Infrastructure.Interfaces;

public interface INwsObservationHttpClient
{
    Task<T> GetAsync<T>(string url) where T : BaseDto;
}